#!/usr/bin/env python3
"""ADR-0004 gate: verify a 2D-only Guidot binary links zero 3D scene/server symbols.

Usage: symbol_audit.py [binary ...]
Without arguments, audits every bin/godot.* executable built with disable_3d
naming is not encoded in the filename, so all given binaries are checked the
same way; run this against the `pixi run build-2d` output.

Exit 0: no 3D symbols. Exit 1: findings listed on stdout.
"""
import glob
import subprocess
import sys
from pathlib import Path

# Class names that must not survive a disable_3d link. Conservative list of
# scene-3D and 3D-server types; math types (Vector3, Basis...) are core and
# legitimately present in 2D builds.
FORBIDDEN = [
    "Node3D",
    "Camera3D",
    "VisualInstance3D",
    "MeshInstance3D",
    "Skeleton3D",
    "PhysicsBody3D",
    "CollisionShape3D",
    "World3D",
    "Light3D",
    "GPUParticles3D",
    "NavigationAgent3D",
]


def audit(binary: Path) -> list[str]:
    nm = subprocess.run(
        ["nm", "-U", str(binary)], capture_output=True, text=True, check=True
    )
    demangled = subprocess.run(
        ["c++filt"], input=nm.stdout, capture_output=True, text=True, check=True
    )
    hits = set()
    for line in demangled.stdout.splitlines():
        for name in FORBIDDEN:
            if name in line:
                hits.add(f"{name}: {line.split()[-1][:120]}")
                break
    return sorted(hits)


def main() -> int:
    targets = [Path(p) for p in sys.argv[1:]] or [
        Path(p) for p in glob.glob("bin/godot.*") if Path(p).is_file()
    ]
    targets = [t for t in targets if t.is_file() and t.stat().st_mode & 0o111]
    if not targets:
        print("symbol_audit: no binaries found (build first: pixi run build-2d)")
        return 2
    failed = False
    for binary in targets:
        hits = audit(binary)
        if hits:
            failed = True
            print(f"FAIL {binary}: {len(hits)} forbidden 3D symbols")
            for h in hits[:20]:
                print(f"  {h}")
        else:
            print(f"PASS {binary}: zero 3D symbols")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""Run the engine's doctest suite (Guidot cases by default) on the editor binary.

Builds are not triggered here; run `pixi run build-tests` first.
Usage: run_engine_tests.py [doctest filter]   (default: *[Guidot]*)
"""
import glob
import subprocess
import sys

pattern = sys.argv[1] if len(sys.argv) > 1 else "*[Guidot]*"
binaries = sorted(glob.glob("bin/godot.*.editor.dev.*")) or sorted(
    glob.glob("bin/godot.*.editor.*")
)
binaries = [b for b in binaries if not b.endswith((".dSYM", ".exp", ".lib"))]
if not binaries:
    sys.exit("run_engine_tests: no editor binary in bin/ (run: pixi run build-tests)")

cmd = [binaries[-1], "--test", f"--test-case={pattern}"]
print("+", " ".join(cmd))
sys.exit(subprocess.call(cmd))

# Guidot — documentation pointer

This fork is **Guidot**: Godot re-exposed as a modular, language-agnostic UI framework through an additive façade (`namespace guidot`), built as a custom module under `guidot/modules/guidot/` with zero upstream build-file diffs.

**The R&D trail lives in [Guidot-RnD](https://github.com/notredamedelinternet/Guidot-RnD)** — prompts, ADRs (the why behind everything here), nomenclature dictionary, audits, and session logs. Decisions are *not* duplicated in this repo; this file is the only pointer.

## Quickstart

```sh
pixi run build           # full editor + guidot façade module
pixi run build-2d        # 2D-only template + façade (ADR-0004 target)
pixi run build-gamedev   # upstream-equivalent build (no guidot code)
pixi run build-tests     # editor + doctest suite
pixi run test            # run [Guidot] test cases
pixi run audit-3d        # verify zero 3D symbols in 2D binaries
```

macOS note: tasks build Metal-only (`vulkan=no accesskit=no angle=no`) so no extra SDKs are needed; run `misc/scripts/install_vulkan_sdk_macos.sh` / `install_accesskit.py` / `install_angle.py` and drop the flags to restore upstream defaults.

## Layout added by Guidot (all new files)

```
pixi.toml                      # build orchestration (ADR-0002)
guidot/modules/guidot/         # the façade module (ADR-0010)
  core/                        # pure aliases (NOMENCLATURE rows 1-3, 5-6)
  widgets/                     # wrapper classes (row 4: Widget)
  tests/                       # doctest smoke tests
tools/guidot/                  # symbol_audit.py, run_engine_tests.py
docs/guidot/                   # this pointer
```

Upstream-file diff surface: one line in `.gitignore` (`.pixi/`). Everything else is additive.

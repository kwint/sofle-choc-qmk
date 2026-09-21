# Sofle Choc firmware

QMK [external userspace](https://docs.qmk.fm/newbs_external_userspace) for a
Sofle Choc v2.1: 2x Pro Micro (ATmega32U4), 2x SSD1306 128x32 OLED, 2x EC11
encoder with push, per-key SK6812 RGB.

Built against mainline `qmk/qmk_firmware` (`keyboards/sofle_choc`), which has
supported this board since brianlow's PR #16736 was merged — the official build
guide still tells you to clone the `choc2` fork branch, and that is out of date.

## Layers

The five layers from the build guide's default layout:

| Layer | Reached by | Contents |
|-------|-----------|----------|
| QWERTY | default | letters, number row, `Mute` / `Play` on the encoder pushes |
| COLEMAK | `Colmak` on Adjust | alternate base layout, remembered across reboots |
| LOWER | left thumb | F1–F12, numbers, symbols, brackets |
| RAISE | right thumb | arrows, Home/End, word-wise motion, Ins/PrtSc/Menu, clipboard |
| ADJUST | LOWER + RAISE together | RGB controls, layout switch, Mac/Win swap, media, `QK_BOOT`, `EE_CLR` |

Encoders, per layer:

| Layer | Left encoder | Right encoder |
|-------|-------------|---------------|
| QWERTY / COLEMAK | volume | page up/down |
| LOWER | RGB hue | RGB saturation |
| RAISE | RGB brightness | RGB speed |
| ADJUST | RGB mode | media prev/next |

`MacWin` on the Adjust layer swaps Ctrl and GUI. The clipboard keys and word
motions follow that swap automatically.

## OLEDs

Both screens are driven, rotated 270° (5 characters wide, 16 lines):
keyboard name, active base layout, active layer, caps-lock, and — on the master
half only — `MAC`/`WIN` plus a live readout of RGB mode/hue/sat/val/speed while
you are holding Adjust.

If the right-hand screen reads upside down, flip `OLED_ROTATION_270` to
`OLED_ROTATION_90` in the non-master branch of `oled_init_user()`.

## Keymap diagram

![Keymap](keymap.png)

`keymap.svg` (vector, crisp at any zoom) and `keymap.png` (1600px wide) are
rendered with [keymap-drawer](https://github.com/caksoylar/keymap-drawer) from
the real `keymap.c`, so they cannot drift from the firmware.

```sh
./draw.sh              # redraw from keymap.yaml
./draw.sh --reparse    # re-read keymap.c first (resets hand-made tweaks)
```

`keymap.yaml` is the intermediate: `--reparse` regenerates it from the
firmware, which discards the layer names, the tidied `QWERTY`/`COLEMAK`
legends and the encoder footer, so re-apply those afterwards.

## Build and flash

The QMK CLI already points at this directory (`user.overlay_dir`), so from
anywhere:

```sh
qmk compile -kb sofle_choc -km quint     # -> sofle_choc_quint.hex here
qmk flash   -kb sofle_choc -km quint     # build + flash the attached half
```

Flash the **same** firmware to both halves, one at a time:

1. Unplug the TRRS cable — never hot-plug it.
2. Plug in the left half, run `qmk flash ...`, tap the reset button twice when
   the console asks (some Pro Micros need the double tap).
3. Unplug, plug in the right half, run the same command again.
4. Unplug, reconnect TRRS, plug USB into the **left** half.

Coming from other firmware (an MX Sofle build, say), clear the stored settings
once afterwards: hold LOWER + RAISE and press `EE_CLR` (the `5` position on the
top row of the left half). Otherwise stale RGB and layout state can persist.

## Flash budget

The ATmega32U4 s. Mainline's stock `sofle_chocxxxxxxxxxxxxxxxxxxxxxxxxxxcc
layer, a logo on the OLED — already uses 91% of it, because the board enables
all 29 RGB matrix animations. This keymap disables all but five in `config.h`
and lands at:

```
24452/28672 (85%, 4220 bytes free)
```

Delete an `#undef ENABLE_RGB_MATRIX_*` line to get an animation back, or add
features into the remaining 4 KB. The build prints the size every time.

## Layout

```
keyboards/sofle_choc/keymaps/quint/
  keymap.c    layers, encoder map, OLED rendering
  config.h    tri-layer, split options, RGB trimming
  rules.mk    features
qmk.json      userspace manifest (build target sofle_choc:quint)
```

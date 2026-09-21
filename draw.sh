#!/usr/bin/env bash
# Regenerate keymap.svg / keymap.png from keymap.c.
#
# keymap.yaml is edited by hand (layer names, tidied legends, footer), so this
# only refreshes it from the firmware when you pass --reparse.
set -euo pipefail
cd "$(dirname "$0")"

if [[ "${1:-}" == "--reparse" ]]; then
    qmk c2json -kb sofle_choc -km quint -o /tmp/sofle_choc.json
    uvx --from keymap-drawer keymap parse -q /tmp/sofle_choc.json -o keymap.yaml
    echo "keymap.yaml regenerated -- re-apply layer names and the footer by hand."
fi

uvx --from keymap-drawer keymap draw keymap.yaml -o keymap.svg

# cairosvg ignores paint-order, which would paint the label halo over the text,
# and needs a font that actually has the transparent-key glyph.
python3 - <<'PY'
s = open('keymap.svg').read()
s = s.replace("    stroke: white;\n    stroke-width: 4;\n    paint-order: stroke;\n", "")
s = s.replace("SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace",
              "DejaVu Sans Mono,Liberation Mono,monospace")
open('/tmp/sofle_choc_render.svg', 'w').write(s)
PY
uvx --from cairosvg cairosvg /tmp/sofle_choc_render.svg -o keymap.png --output-width 1600

echo "wrote keymap.svg and keymap.png"

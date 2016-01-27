# Fdf

__Installation:__

* `git clone https://github.com/wwatkins42/42Projects.git`
* `cd ./Fdf`
* `make`
* `./fdf [map file_path]`

**Usage:**
* `./fdf [map file_path] [-p file_path] [-w width] [-h height] [--help]`

**Options:**
* `-p` [`file_path`] loads with a defined color palette.
* `-w` [`window_width`] loads with defined window width.
* `-h` [`window_height`]  loads with defined window height.
* `--help`  display help text.

**Exemple:**
* `./fdf maps/pylone.fdf -p palette/palette.fdfcolor -w 1500 -h 1200`

**Keys:**
* &#8593; &#8592; &#8595; &#8594;: move around
* `+` `-`: zoom
* `m`: change draw method
* `p`: change color (only if multiple color are in loaded palette, if loaded)
* `i` `k`: change maximum terrain elevation
* &#8670; &#8671;: change color elevation

![fdf_screenshot_2](/screenshots/screenshot_fdf_2.png?raw=true "fdf")
![fdf_screenshot_1](/screenshots/screenshot_fdf_1.png?raw=true "fdf")

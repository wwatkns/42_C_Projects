# Fract'ol

_This project consist of creating a small fractal exploration program._

__Installation:__

* `git clone https://github.com/wwatkins42/42Projects.git`
* `cd ./Fractol`
* `make`
* `./fractol [type]`

**Usage:**
* `./fractol [type] [-w width] [-h height] [--help]`
* type: 
  * `julia`
  * `mandelbrot`
  * `burningship`
  * `tricorn`

**Options:**
* `-w` [`window_width`] loads with defined window width.
* `-h` [`window_height`]  loads with defined window height.
* `--help`  display help text.

**Example:**
* `./fractol burningship -w 640 -h 640`

**Keys:**
* `+` `-` or `mouse wheel`: zoom on mouse position
* `mouse`: change julia settings
* `o`: switch background color
* `p`: change color palette
* &#8670; &#8671;: change number of iteration

![fractol_screenshot_1](/screenshots/screenshot_fractol_1.png?raw=true "fractol")
![fractol_screenshot_2](/screenshots/screenshot_fractol_2.png?raw=true "fractol")

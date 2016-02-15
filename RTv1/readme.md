# RTv1

_This project is a first step towards the realization of a raytracing program, in order to create computer generated pictures._

__Installation:__

* `git clone https://github.com/wwatkins42/42Projects.git`
* `cd ./RTv1`
* `make`
* `./rtv1`

**Usage:**
* `./rtv1 [file_path] [-w width] [-h height] [-s supersampling] [-g gamma] [-f fov] [-m maxdepth] [-x angle] [-y angle] [-z angle] [--help]`

**Options:**
* `-m` [`file_path`]      loads map from file_path.
* `-t` [`file_path`]      loads textures pack from file_path.
* `-w` [`window_width`] loads with defined window width.
* `-h` [`window_height`]  loads with defined window height.
* `-s` [`supersampling`] set specified supersampling value.
* `-g` [`gamma`] set specified gamma value.
* `-f` [`fov`] set defined fov value.
* `-m` [`max_depth`] set defined maximum reflection depth value.
* `-x` [`angle(deg)`] set defined camera angle on x axis.
* `-y` [`angle(deg)`] set defined camera angle on y axis.
* `-z` [`angle(deg)`] set defined camera angle on z axis.
* `--help`  display help text.

**Example:**
* `./rtv1 resource/scene/circlebox.scene -w 1920 -h 1080 -g 0.7 -f 70 -x 38 -y 34 -z 30 -s 2`

**Keys:**
* `esc` quit program.

![rtv1_screenshot_1](/screenshots/screenshot_rtv1_1.png?raw=true "rtv1")
![rtv1_screenshot_2](/screenshots/screenshot_rtv1_2.png?raw=true "rtv1")

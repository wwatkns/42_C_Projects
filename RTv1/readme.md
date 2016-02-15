# Wolf3d

_This project consist of creating a realistic graphical representation of what we could see inside of a labyrinth._
_The representation is realised using the raycasting technique._

__Installation:__

* `git clone https://github.com/wwatkins42/42Projects.git`
* `cd ./Wolf3d`
* `make`
* `./wolf3d`

**Usage:**
* `./wolf3d [-m file_path] [-t file_path] [-w width] [-h height] [--help]`

**Options:**
* `-m` [`file_path`]      loads map from file_path.
* `-t` [`file_path`]      loads textures pack from file_path.
* `-w` [`window_width`] loads with defined window width.
* `-h` [`window_height`]  loads with defined window height.
* `--help`  display help text.

**Example:**
* `./wolf3d -m resource/map/labyrinth.map -t resource/template/pack_3.template -w 1000 -h 640`

**Keys:**
* &#8593; &#8592; &#8595; &#8594; or `w` `a` `s` `d`: move around.
* `q`, `e` or `mouse`: rotate view
* `m`: *change mouse rotation*

![wolf3d_screenshot_1](/screenshots/screenshot_wolf3d_1.png?raw=true "wolf3d")
![wolf3d_screenshot_2](/screenshots/screenshot_wolf3d_2.png?raw=true "wolf3d")

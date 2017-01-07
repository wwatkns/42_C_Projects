# Malloc

_This project is about recoding the malloc, free and realloc function._

__Installation:__

* `git clone https://github.com/wwatkins42/42Projects.git`
* `cd ./Malloc`
* `make`
* `./test/run.sh ./[file]`

**Usage:**
* `./test/run.sh ./[file]`
* `run.sh is a script used to inject my malloc library to use in executables instead of the default implementation of malloc.`

**Example:**
* `gcc ./test/test1 -o test1`
* `./test/run.sh /usr/bin/time -l ./test1`

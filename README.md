
A sa-mp c++ racing gamemode inspired by need for speed world etc.

## Requirements

* mysql c connector (https://dev.mysql.com/downloads/connector/c/ or mariadb-devel)

## Building

* Windows: edit `env.bat` as needed and run `buildclean.bat`
* Linux: run `make`

## Notes

* This is my first 'serious' c(pp) project, so there are probably lots of weird twists in the code.
* The windows build environment wants to copy the freshly built plugin to a samp server in a folder called `samp03`
* Windows vs build has only debug targets, because release builds are compiled on linux anyways.
* (Windows) Build files have been stripped down to the bare minimum. I haven't tried to build on any machine other than mine, but I *guess* it should work.

### License

[GNU AGPLv3](/LICENSE)

------------------------------------------------

Made possible thanks to https://github.com/Zeex/sampgdk


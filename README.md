OpenGL CMake Skeleton [![Build Status](https://travis-ci.org/ArthurSonzogni/OpenGL_CMake_Skeleton.svg?branch=master)](https://travis-ci.org/ArthurSonzogni/OpenGL_CMake_Skeleton)
=======================

A ready to use C++11 CMake OpenGL skeleton using **GLFW**, **Glew** and **glm**. (use git submodules)

It compiles on:
 * **WebAssembly**  (on the webassembly branch. See instruction below)
 * Linux
 * Windows
 * Mac

It can compile for the Web with WebAssembly thanks to emscripten, as well as on
Linux, Windows and Mac.

Shader class and example Application are included.

![output result](output.gif)

I am open to any comments and contributions.

Clone (With submodules):
========================

```
git clone --recursive git@github.com:ArthurSonzogni/OpenGL_CMake_Skeleton.git
```

Alternatively, if you don't used the --recursive option, you can type:
```bash
git submodule init
git submodule update
```

usage (WebAssembly) : 
---------------------
Switch to the webassembly branch
```
git checkout webassembly
```

Install emscripten, then
```bash
mkdir build_emscripten
cd build_emscripten
CC=emcc CXX=em++ cmake ..
make
python -m SimpleHTTPServer 8000
```

Now, visit [http://localhost:8000](http://localhost:8000)

usage (Linux) : 
---------------
Some standard library to install:
```bash
sudo apt-get install cmake libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev

Open the directory into a terminal
```bash
mkdir build
cd build
cmake ..
./main
```

usage (Windows) :
-----------------
For instance :
* cmake-gui .
* Configure (Choose for example Visual Studio generator)
* Generate
Launch the generated project in your favorite IDE and run it.

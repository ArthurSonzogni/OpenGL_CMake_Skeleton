OpenGL CMake Skeleton :
=======================

A ready to use C++11 CMake skeleton using GLFW, Glew and glm.

Shader and Application class are included too.

![output result](output.gif)

git submodules :
================

This project use the git submodules system.
To clone this repository you must add the --recursive option.
```
git clone git@github.com:ArthurSonzogni/OpenGL_CMake_Skeleton.git --recursive
```
Alternatively, if you don't used the --recursive option, you can type:
* git submodule init
* git submodule update


Requirement:
============
* C++11 compiler
* cmake (>= 2.8)
* OpenGL drivers (>=3.0)
* Some standard library depending on your platform

usage (Linux) : 
---------------
To build, you could need to have the following library (not exhaustive) on ubuntu :
* libxi-dev
* libxinerama-dev
* libxcursor-dev
* libglew-dev
* libxrandr-dev

Open the directory into a terminal
```
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


usage (Mac Os X) :
------------------
(instructions are coming soon.. ,  (or never) )

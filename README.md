# ras-exemption-project

This is my implementation for the exemption project of RAS. It uses raylib as the graphics library and you can add/remove circles that are connected to each other. The data is stored in a linked list. `CMakeLists.txt` is adapted from raylib's [repository](https://github.com/raysan5/raylib/tree/master/projects/CMake).

# Installing and running
```
cmake -B build
cd build/
make
./ras_exemption_project
```

# Usage
* Left mouse click adds a new random circle.
* Right mouse click removes the last added circle.
* Scrolling up and down zooms in and out.
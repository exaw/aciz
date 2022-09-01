
curve.h - interface for curve objects

circle.*
ellipse.*
helix.* - implementation of curves

./svg directory - sample curves svg rendering results

simple_svg_1.0.0.hpp - third party library (https://github.com/adishavit/simple-svg/)

main.cpp - step by step code for main task document (xxx C++ assignment v4 for probationers.pdf)
draw_screen.cpp - creating and console rendering some sample curve
draw_svg.cpp - creating and svg rendering some sample curve
tbb_algo.cpp - tbb multithreaded implementation of radii sum


building
cmake ./
cmake --build ./


result
aciz-lib shared library
aciz-main application
aciz-screen application
aciz-svg application


was builded on:
Fedora Linux
gcc (GCC) 10.3.1 20210422 (Red Hat 10.3.1-1)


building dependencies:
https://github.com/oneapi-src/oneTBB

cmake_minimum_required(VERSION 3.2)
project(aciz)

add_library( aciz-lib SHARED
        circle.cpp
        ellipse.cpp
        point.h
        point.cpp
        helix.h
        helix.cpp
        )

add_executable( aciz-screen draw_screen.cpp simple_svg_1.0.0.hpp)
target_link_libraries( aciz-screen aciz-lib )

add_executable( aciz-svg draw_svg.cpp simple_svg_1.0.0.hpp )
target_link_libraries( aciz-svg aciz-lib )

add_executable( aciz-main main.cpp tbb_algo.cpp)
target_link_libraries( aciz-main aciz-lib tbb )

set_target_properties ( aciz-screen PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties ( aciz-main PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )


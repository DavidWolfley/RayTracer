cmake_minimum_required(VERSION 3.26)
project(RayIsTracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(RayIsTracing RayTracerMain.cpp
        vec3.hpp
        color.hpp
        ray.hpp
        hittable.hpp
        sphere.hpp
        hittablelist.hpp
        rtweekend.hpp
        interval.hpp
        camera.hpp
        material.hpp
        aarect.hpp)

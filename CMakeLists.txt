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
        aarect.hpp
        aabb.hpp
        bvh.hpp
        texture.hpp
        rtw_stb_image.hpp)

find_package(OpenMP REQUIRED)

if(OpenMP_CXX_FOUND)
    target_link_libraries(RayIsTracing OpenMP::OpenMP_CXX)
else()
    target_link_libraries(RayIsTracing)
endif()
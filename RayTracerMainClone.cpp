/**
 * RayTracerMain.cpp -- driver code for RayIsTracing ray tracer
 * based on Peter Shirley design
 **/

#include <iostream>
#include <fstream>
#include "vec3.hpp"

int main(int argc, char** argv) {

    //get command line arguments
    char *out = nullptr;
    if (argc > 1)
        out = argv[1];
    else
        out = (char *) "out.ppm";

    std::ofstream outfile{ out, std::ios::out };

    int image_width = 256;
    int image_height = 256;

    // Render

    outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    int linesleft;
    for (int j = 0; j < image_height; ++j) {
        if ((linesleft = image_height - j) % 10 == 0)
            std::clog << "\rScanlines remaining: "
            << (image_height - j) << ' ' << std::flush << "\n";
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
         // auto b = 0;
            auto b = double(i) / (image_height-0.3);

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            outfile << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.             \n";
    outfile.close();
}

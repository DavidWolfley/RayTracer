#include "rtweekend.hpp"
#include "camera.hpp"
#include "hittablelist.hpp"
#include "sphere.hpp"
#include "color.hpp"
#include "material.hpp"
#include "aarect.hpp"

int main() {
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.9, 0.9, 0.9));
    auto material_center = make_shared<dielectric>(1.5);
    auto material_left   = make_shared<metal>(color(0.1, 0.1, 0.9), 0.3);
    auto material_right  = make_shared<metal>(color(0.1, 0.9, 0.1), 0.3);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.2, -3.0),   0.7, material_center));
    world.add(make_shared<sphere>(point3(-0.7,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(0.7,    0.0, -1.0),   0.5, material_right));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 720;
//  cam.image_width  = 1920;
    cam.samples_per_pixel = 200;
    cam.max_depth         = 50;

    cam.render(world, 0, 0);
}
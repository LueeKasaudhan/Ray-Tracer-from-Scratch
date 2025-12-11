#include<iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"
#include "ray.h"

using namespace std; 

color ray_color(const ray& r) {
  vec3 unit_direction = unit_vector(r.direction());
  auto a = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - a)*color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main(){

  // setting world size
  auto aspect_ratio = 16.0/9.0;
  int image_width = 1920;
  int image_height = int(image_width/aspect_ratio);
  image_height = image_height<1 ? 1 : image_height;

  //setting camera
  auto focal_length = 1.0;
  auto camera_center = point3(0,0,0);

  //setting viewport for fov
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width)/image_height);
  // viewport directions.
  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, -viewport_height, 0);
  auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
  // setting pixel space and it's data
  auto pixel_delta_u = viewport_u/image_width;
  auto pixel_delta_v = viewport_v/image_height;
  auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	
  ofstream file("image.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  // rendering
  file
	<< "P3\n"
	<< image_width
	<< ' '
	<< image_height
	<< "\n255\n";

  for(int i = 0; i < image_height; i++) {
    for(int j = 0; j < image_width; j++) {
      auto pixel_center_for_each_pixel = pixel00_loc + (i * pixel_delta_v) + (j * pixel_delta_u);
      auto ray_direction = pixel_center_for_each_pixel - camera_center;
      ray r(camera_center, ray_direction);

      color pixel_color = ray_color(r);
      write_color(file, pixel_color);
    }
  }


	return 0 ;
}

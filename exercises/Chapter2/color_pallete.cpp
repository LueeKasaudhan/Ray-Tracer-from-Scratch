#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "vec3.h"
#include "color.h"

using namespace std;

#define WIDTH 512
#define HEIGHT 512

// linear interpolation
vec3 lerp(const vec3& color_max, const vec3& color_min, float blend_factor);

int main() {
  ofstream file("color_pallete.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  
  const int image_width = WIDTH;
  const int image_height = HEIGHT;

  file<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";


  for(int i=0; i<image_height; i++) {
    for(int j=0; j<image_width; j++) {
      color color_a(1,0,0);
      color color_b(0,1,0);
      color color_c(0,0,1);

      float center_x = image_width/2;
      float center_y = image_height/2;

      vec3 pixel_pos(i, j, 0);
      vec3 center(center_x, center_y, 0);

      double distance = (pixel_pos - center).length();
      double max_distance = sqrt(center_x*center_x + center_y*center_y);

      float blend_factor = distance/max_distance;
      
      double u = double(i) / double(image_width-1);
      double v = double(j) / double(image_height-1);

      vec3 horiz = lerp(color_a, color_b, u);
      vec3 vert = lerp(color_b, color_c, v);

      write_color(file, lerp(vert, horiz, v));
    }
  }

  return 0;
}

// Definiton
vec3 lerp(const vec3& color_max, const vec3& color_min, float blend_factor) {
  // the blend_factor adjust the brightness between the color_max and color_min
  if(blend_factor<0 || blend_factor>1.0) {
    cerr << "enter the correct blend_factor" << endl;
    blend_factor = clamp(blend_factor, 0.0f, 1.0f);
  }
  vec3 interpolated_value = ((1-blend_factor)*color_max) + blend_factor*color_min;
  return interpolated_value;
}

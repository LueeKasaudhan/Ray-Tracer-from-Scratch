#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "../../vec3.h"
#include "../../color.h"

using namespace std;

#define WIDTH 512
#define HEIGHT 512

// linear interpolation
vec3 lerp(const vec3& color_max, const vec3& color_min, float blend_factor);

int main() {
  ofstream file("lerp_image.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  
  const int image_width = WIDTH;
  const int image_height = HEIGHT;

  file<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";


  for(int i=0; i<image_height; i++) {
    for(int j=0; j<image_width; j++) {
      float center_x = image_width  / 2.0;
      float center_y = image_height / 2.0;

      // each pixel_pos decided 
      vec3 pixel_pos(i, j, 0);
      vec3 center(center_x, center_y, 0); //fixed

      // distance = radius of the image from the center, for each row and column
      float distance = (pixel_pos - center).length();
      float max_dist = sqrt(center_x*center_x + center_y*center_y); // fixed

      float t = distance / max_dist;      // normalized 0 → 1.0; x 0-206 row
                                          // y: 0-206 column
                                          // changes for each pixel from 0 to 1

      vec3 pixel_color = lerp(vec3(0,0,0), vec3(1,1,1), t);

      write_color(file, pixel_color);

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

/*
 * if we take the 9x9 image then this is how the vlaue will go.
 * Notice how:
      The center is 0
      Moving outward increases gradually
      The corners have the highest distance
 * This is exactly the value code computed for each pixel.
 
--- Distance map ---
  5.6   5.0   4.2   3.6   3.5   3.6   4.2   5.0   5.6
  5.0   4.2   3.2   2.2   1.5   2.2   3.2   4.2   5.0
  4.2   3.2   1.8   1.2   0.7   1.2   1.8   3.2   4.2
  3.6   2.2   1.2   0.5   0.1   0.5   1.2   2.2   3.6
  3.5   1.5   0.7   0.1   0.0   0.1   0.7   1.5   3.5
  3.6   2.2   1.2   0.5   0.1   0.5   1.2   2.2   3.6
  4.2   3.2   1.8   1.2   0.7   1.2   1.8   3.2   4.2
  5.0   4.2   3.2   2.2   1.5   2.2   3.2   4.2   5.0
  5.6   5.0   4.2   3.6   3.5   3.6   4.2   5.0   5.6


--- blend_factor map ---
 1.00  0.89  0.75  0.64  0.63  0.64  0.75  0.89  1.00
 0.89  0.75  0.57  0.39  0.27  0.39  0.57  0.75  0.89
 0.75  0.57  0.32  0.21  0.13  0.21  0.32  0.57  0.75
 0.64  0.39  0.21  0.09  0.02  0.09  0.21  0.39  0.64
 0.63  0.27  0.13  0.02  0.00  0.02  0.13  0.27  0.63
 0.64  0.39  0.21  0.09  0.02  0.09  0.21  0.39  0.64
 0.75  0.57  0.32  0.21  0.13  0.21  0.32  0.57  0.75
 0.89  0.75  0.57  0.39  0.27  0.39  0.57  0.75  0.89
 1.00  0.89  0.75  0.64  0.63  0.64  0.75  0.89  1.00

--- brightness value of the color_max ---
 0.00  0.11  0.25  0.36  0.37  0.36  0.25  0.11  0.00
 0.11  0.25  0.43  0.61  0.73  0.61  0.43  0.25  0.11
 0.25  0.43  0.68  0.79  0.87  0.79  0.68  0.43  0.25
 0.36  0.61  0.79  0.91  0.98  0.91  0.79  0.61  0.36
 0.37  0.73  0.87  0.98  1.00  0.98  0.87  0.73  0.37
 0.36  0.61  0.79  0.91  0.98  0.91  0.79  0.61  0.36
 0.25  0.43  0.68  0.79  0.87  0.79  0.68  0.43  0.25
 0.11  0.25  0.43  0.61  0.73  0.61  0.43  0.25  0.11
 0.00  0.11  0.25  0.36  0.37  0.36  0.25  0.11  0.00


*/

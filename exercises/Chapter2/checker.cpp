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
  ofstream file("checker_image.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  
  const int image_width = WIDTH;
  const int image_height = HEIGHT;

  file<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";


  for(int i=0; i<image_height; i++) {
    for(int j=0; j<image_width; j++) {
      int tile_size = 51;
      int tile = ((i/tile_size)+(j/tile_size))%2;
//      vec3 tiles(tile, tile, tile);
      vec3 tiles = tile == 0 ? vec3(0.1,0.1,0.1) : vec3(0.9,0.9,0.9);
      write_color(file, tiles);
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

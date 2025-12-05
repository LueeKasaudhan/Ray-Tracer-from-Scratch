#include <iostream>
#include <stdio.h>
#include <fstream>

#include "../../vec3.h"
#include "../../color.h"

using namespace std;

int main() {
  ofstream file("gradient_image.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  
  const int image_width = 512;
  const int image_height = 512;

  file<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";


  for(int i=0; i<image_height; i++) {
    for(int j=0; j<image_width; j++) {
      vec3 pixelColor = color((1-(double(j)/(image_width-1))),0.2,double(j)/(image_width-1));
      write_color(file, pixelColor);
    }
  }
  
  return 0;
}

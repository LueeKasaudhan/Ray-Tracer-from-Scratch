#include<iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

using namespace std; 

int main(){
	
  ofstream file("image.ppm");
  if(!file.is_open()) {
    cerr << "failed to open the file";
    return EXIT_FAILURE;
  }
  // image size
	const int image_height = 512;
	const int image_width = 512;
  // rendering
  file
	<< "P3\n"
	<< image_width
	<< ' '
	<< image_height
	<< "\n255\n";

	for(int j = image_height - 1; j >= 0; --j) {
		for (int i = 0; i <= image_width; ++i) {
      auto pixel_color = color(double(image_width-1-i)/(image_width-1), double(image_height-1-j)/(image_height-1), 0);
			// double r = double(i)/(image_width-1);
			// double g = double(j)/(image_height-1);
			// double b = 0.25;

      write_color(file, pixel_color);
			
			// int ir = static_cast<int>(255.999*r);
			// int ig = static_cast<int>(255.999*g);
			// int ib = static_cast<int>(255.999*b);
		// 	cout
		// 	<< ir
		// 	<< ' '
		// 	<< ig
		// 	<< ' '
		// 	<< ib
		// 	<< '\n';
		}
	}
	return 0 ;
}

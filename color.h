#pragma once

#include "vec3.h"

#include <iostream>

using color = vec3;
// setting up alias for any variable.

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // transforming the 0,1 components into the rgb 8 bit values; see the notes.
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  out << rbyte << " " << gbyte << " " << bbyte << "\n";

}


#pragma once

#include "vec3.h"
#include "color.h"

class properties {
  public:

    vec3 lerp(const vec3& color_max, const vec3& color_min, float blend_factor) {
      // the blend_factor adjust the brightness between the color_max and color_min
      if(blend_factor<0 || blend_factor>1.0) {
        cerr << "enter the correct blend_factor" << endl;
        blend_factor = clamp(blend_factor, 0.0f, 1.0f);
      }
      vec3 interpolated_value = ((1-blend_factor)*color_max) + blend_factor*color_min;
      return interpolated_value;
    }

}

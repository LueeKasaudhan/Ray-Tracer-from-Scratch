#ifndef VEC3_H
#define VEC3_h

#include<cmath>
#include<iostream>

class vec3 {
  public:
    double e[3];
    vec3(): e{0,0,0} {} 
    vec3(double x, double y, double z): e{x,y,z} {} 

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-(){
      return vec3(-e[0],-e[1],-e[2]);
    }
      // unary negation for returning new vector whose components are negated.
    
    double operator[](int i) const {
      return e[i];
    }
      // It is a const object
      // returns value by safe copy not by reference. read-only object
      // uses: double x = v[1]
      // v[1]=10 error because v is const here


    double& operator[](int i) {
      return e[i];
    }
      //uses: double& x = v[1] --> x becomes alias of v[1]
      //v[1]=10 allowed here
      //x = 50 --> changes the value of v[1] too because x alias for v[1]

    vec3& operator+=(const vec3& v) {
      e[0] += v.e[0];
      e[1] += v.e[1];
      e[2] += v.e[2];
      return *this;
    }
    /*
      const vec3& v --> so that the function doesn't modify v.
      & is used so that we don't just copy the v and use it.
      by default if we don't use '&' the compiler will just copy the value
      into some temp variable and use it.
      *this --> dereference the object created.
      e.g. vec3 obj_1
      then the *this will dereference the obj_1.
      operator chaining, above we can do a += b += c;
      because we are referencing the object directly
      it'll work something like this:-
      1. object b will be referenced and modified and object c is the
         const vec3. here b will be dereferenced by *this and returned.
      3. object a will be referenced and modified and object b is now
         the const vec3. here a will be dereferenced by *this and returned.
      */


    vec3& operator*=(double t) {
      e[0] *= t;
      e[1] *= t;
      e[2] *= t;
      return *this;
    }
      // can also write 'const double& t' but it would be 
      // an overkill

    vec3& operator/=(double t) {
      return *this *= 1/t; 
    }
      // operator/= calls operator*=
      // operator*= performs real math
      // what it does is that v *= 1/t;
      // we can also write this instead of this.
      // e[0] /= t;
      // e[1] /= t;
      // e[2] /= t;
      // return *this;
      //
    double length() const {
      return std::sqrt(length_squared());
    } 
    double length_squared() const {
      return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    
    
}

using point3 = vec3;
//point3 is an alias for vec3

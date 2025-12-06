

---

# ✅ **Progress Checklist**

---

## 1. **Output an Image**

### ⭐ Concept: Learn how to generate any image at all

- [x]  Understand the **PPM image format**
    
- [x]  Write basic C++ code to output text-based pixel data
    
- [x]  Render the first **gradient image**
    
- [ ]  Add a **progress indicator** using `std::clog`
    

---

## 2. **The vec3 Class**

### ⭐ Concept: Build the mathematical backbone

- [x]  Implement `vec3` type with `x, y, z`
    
- [x]  Implement vector operations:
    
    - [x]  addition
        
    - [x]  subtraction
        
    - [x]  scaling
        
    - [x]  division
        
    - [x]  dot product
        
    - [x]  cross product
          
- [x] understanding vectors, functionals, functions, vector spaces.
      
	- [x] meaning of dot product
	      
	- [x] Functionals
	      
	- [x] Vector spaces
	      
	- [x] Normals and it's transformations
	      
	- [x] Covectors
	      
	- [x] Gradients
	      
	- [x] Column vectors
	      
	- [x] Row vectors
	      
	- [x] Dual spaces
      
- [x]  Implement `unit_vector`
    
- [x]  Create aliases `color` and `point3`
    
- [x]  Implement the `write_color()` helper
      
- [ ] Do exercises.

---

## 3. **Rays, Camera, and Background**

### ⭐ Concept: Fire rays into the scene

- [ ]  Implement `ray` class with `origin`, `direction`, and `at(t)`
    
- [ ]  Understand image coordinates vs. 3D coordinates
    
- [ ]  Implement **simple camera**
    
- [ ]  Compute pixel ray directions
    
- [ ]  Implement sky gradient using lerp
    

---

## 4. **Adding a Sphere**

### ⭐ Concept: Ray-object intersection

- [ ]  Derive ray–sphere intersection equation
    
- [ ]  Implement discriminant-based hit test
    
- [ ]  Render first sphere as red blob
    
- [ ]  Replace background gradient after sphere hit detection
    

---

## 5. **Surface Normals**

### ⭐ Concept: Lighting begins

- [ ]  Compute surface normals at hit points
    
- [ ]  Visualize normals using color mapping
    
- [ ]  Handle both positive and negative roots
    
- [ ]  Normalize normal vectors
    

---

## 6. **Hittable Abstractions**

### ⭐ Concept: Object-oriented ray tracing

- [ ]  Implement `hit_record`
    
- [ ]  Implement abstract `hittable` class
    
- [ ]  Implement sphere as a hittable object
    
- [ ]  Compute **front-face** vs **back-face** normals
    
- [ ]  Store corrected normal using `set_face_normal()`
    

---

## 7. **Multiple Objects**

### ⭐ Concept: A scene is a list of objects

- [ ]  Implement `hittable_list`
    
- [ ]  Add multiple spheres to the scene
    
- [ ]  Track closest hit using `ray_tmin` and `ray_tmax`
    
- [ ]  Render results with two-sphere scene (ground + sphere)
    

---

## 8. **Interval Class**

### ⭐ Concept: Range constraints

- [ ]  Implement `interval` class
    
- [ ]  Handle empty and infinite intervals
    
- [ ]  Use interval for hit checks and t-range
    

---

## 9. **Camera Abstraction**

### ⭐ Concept: Move camera setup into a class

- [ ]  Create camera class
    
- [ ]  Encapsulate viewport + pixel delta calculations
    
- [ ]  Encapsulate main render loop
    
- [ ]  Produce identical output via clean camera API
    

---

## 10. **Antialiasing**

### ⭐ Concept: Remove jagged edges

- [ ]  Add RNG utilities
    
- [ ]  Implement random sampling in each pixel
    
- [ ]  Generate multiple samples per pixel
    
- [ ]  Update color function to accumulate samples
    
- [ ]  Divide and gamma-correct pixel colors
    

---

## 11. **Diffuse Materials**

### ⭐ Concept: Realistic light scattering

- [ ]  Implement Lambertian reflection
    
- [ ]  Add random sample generation in hemisphere
    
- [ ]  Avoid shadow acne using a ray epsilon
    
- [ ]  Clamp recursion depth
    
- [ ]  Implement gamma correction properly
    

---

## 12. **Metal Material**

### ⭐ Concept: Reflective surfaces

- [ ]  Create abstract `material` class
    
- [ ]  Implement perfect mirrors
    
- [ ]  Implement fuzzy reflection using random vector
    
- [ ]  Add metal spheres to scene
    

---

## 13. **Dielectric (Glass) Material**

### ⭐ Concept: Refraction + Fresnel

- [ ]  Implement Snell’s law
    
- [ ]  Compute refraction vector
    
- [ ]  Handle total internal reflection
    
- [ ]  Implement Schlick approximation
    
- [ ]  Render hollow glass sphere
    

---

## 14. **Positionable Camera**

### ⭐ Concept: Move camera anywhere

- [ ]  Add camera world-position
    
- [ ]  Add look-at system
    
- [ ]  Compute camera basis vectors
    
- [ ]  Add vertical field of view
    
- [ ]  Add aspect ratio support
    

---

## 15. **Defocus Blur**

### ⭐ Concept: Depth of field

- [ ]  Add lens_radius
    
- [ ]  Add focal distance
    
- [ ]  Sample random points in lens disk
    
- [ ]  Produce background blur for objects behind focus
    

---

## 16. **Final Scene**

### ⭐ Concept: Full-featured path tracer

- [ ]  Random scene generator
    
- [ ]  Mixture of Lambertian + metal + dielectric objects
    
- [ ]  Camera positionable anywhere
    
- [ ]  Defocus blur
    
- [ ]  High sample count
    
- [ ]  Long render with progressive scanlines
    

---

## 17. **Where Next**

### ⭐ Concept: Move to the next books

-  Book 2 — Ray Tracing: The Next Week
    
-  Book 3 — Ray Tracing: The Rest of Your Life
    

---

# 🏁 **Finish Line**

Once all checkpoints are done, you have built:

- A full **path tracer**
    
- With materials
    
- With surfaces
    
- With reflection + refraction
    
- With antialiasing
    
- With depth of field
    
- With movable camera
    

…from scratch.


---
# Notes
---

**PPM format** :- 
	Simplest image file format.
	Human-readable.
	Doesn't require any library.
**P3** :
	ASCII color image.
	255 --> maximum color intensity for RGB
```
P3
512 512
255
0 255 63
0 255 63
1 255 63
1 255 63
2 255 63
2 255 63
3 255 63
3 255 63
4 255 63
4 255 63
5 255 63
5 255 63
6 255 63
6 255 63

```
- **This is the Header of the PPM file format**
	P3 --> ascii ppm image
	512 512 --> total 512 column and 512 rows = 262144 total pixels
	255 --> max color value for every r, g, and b value for each pixel --> 255 brightest and 0 the darkest
	*-If  the value was 99 then the brightest would be 99 and darkest would be 0-*
- **The Single data triplet r,g, and b**
	Pixel 1 → (0, 255, 63)
	Pixel 2 → (0, 255, 63)
    Pixel 3 → (1, 255, 63)
    Pixel 4 → (1, 255, 63)
    Pixel 5 → (2, 255, 63)
    Pixel 6 → (2, 255, 63)
	*R is slowely increasing*
	*G is slowely decreasing(here it may  seem constant, but at the end of the full  ppm file it is 0 which means that it is slowely decreasing*
	*B is constant*
- **Mapping Rules**
	The _first pixel_ is the **top-left** pixel of the image.
    Pixels go **left → right**, **row by row**.
    After 512 pixels, you move to the next row.
```
+-----------------------------------------------------------+
| px0 | px1 | px2 | px3 | ... | px511                      |  <- Row 0
+-----------------------------------------------------------+
| px512 | px513 | px514 | ... | px1023                     |  <- Row 1
+-----------------------------------------------------------+
| ...                                                       |
+-----------------------------------------------------------+
| Row 511                                                   |
+-----------------------------------------------------------+

```

**Image Flipping**
	if you wanna flip the image just flip the pixels => it'll be flipped.

# 🧠 1. What _is_ a Ray (Concept)

A ray is nothing but a parametric line:

P(t)=A+t⋅b

- **A** = origin
    
- **b** = direction
    
- **t** = parameter (distance along the ray)
Exactly — and you just unlocked the **entire intuition of ray tracing** in one line 😂

Let’s break it down cleanly and deeply (your style), because this analogy is _not only correct_, it's **perfect**.

---

# 🎯 Yes, **P(t) = A + t·b** is the 3D equivalent of **y = mx + c**

Let’s map terms:

|Line Equation|Ray Equation|Meaning|
|---|---|---|
|**c**|**A**|Starting point (intercept)|
|**m**|**b**|Direction (slope)|
|**x**|**t**|Parameter you increase to move forward|
|**y(x)**|**P(t)**|Position after moving|

## ✨ The difference:

- `y = mx + c` works in **1D/2D**
    
- `P(t) = A + t·b` works in **3D space**
    

But both describe:

> A point that moves along a straight line as the parameter increases.

---

# 📌 Why the analogy is perfect

### **1. c = intercept**

Just like `c` shifts your line up or down,  
`A` shifts your ray to wherever the camera is.

### **2. m = slope**

Just like slope decides the direction of the line,  
`b` decides which direction the ray travels in 3D.

### **3. x = t**

As `x` increases, you move along the line.  
As `t` increases, you travel forward along the ray.

### **4. y = mx + c → output**

As `P(t)` increases, you get positions in 3D space.

---

# 📐 Visual Intuition

### **In 2D:**

```
y = mx + c  
x = parameter
```

You change x → you move horizontally along the line.

### **In 3D:**

```
P(t) = A + t·b  
t = parameter
```

You change t → you move along the ray in 3D space.

Same concept. Just more axes.

---

# 🔥 Low-level interpretation (you'll love this)

`A + t·b` is literally:

- Start at some address (`A`)
    
- Add `t` copies of a direction vector (`b`)
    
- End up somewhere else in 3D space
    

This is exactly how CPUs walk through points in 3D:  
add → add → add → add

No curves. No fancy math.  
Just linear algebra + a loop.

---

Because hitting an object is simply:

### “Find t where the ray hits the object.”

Every intersection problem becomes:

- Plug P(t) into object equation
    
- Solve for t
    
- If t > 0 → ray hits it
    
- If t < 0 → behind camera, ignore
    

That's why this equation is the **core** of ray tracing.

---

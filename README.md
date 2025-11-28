

---

# ✅ **Progress Checklist**

---

## 1. **Output an Image**

### ⭐ Concept: Learn how to generate any image at all

- [ ]  Understand the **PPM image format**
    
- [ ]  Write basic C++ code to output text-based pixel data
    
- [ ]  Render the first **gradient image**
    
- [ ]  Add a **progress indicator** using `std::clog`
    

---

## 2. **The vec3 Class**

### ⭐ Concept: Build the mathematical backbone

- [ ]  Implement `vec3` type with `x, y, z`
    
- [ ]  Implement vector operations:
    
    - [ ]  addition
        
    - [ ]  subtraction
        
    - [ ]  scaling
        
    - [ ]  division
        
    - [ ]  dot product
        
    - [ ]  cross product
        
- [ ]  Implement `unit_vector`
    
- [ ]  Create aliases `color` and `point3`
    
- [ ]  Implement the `write_color()` helper
    

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

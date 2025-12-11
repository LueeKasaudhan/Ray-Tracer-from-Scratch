

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

# 🔥 1. How does the ray “move”?

The ray equation:

P(t) = A + t * b  

means:

- Start at **A**
    
- Move in direction **b**
    
- Take **t** steps of size **b**
    

So the ray “moves” by nothing more than:

```
P_next = P_prev + (Δt * b)
```

If Δt = 1 → P = A + b  
If Δt = 0.1 → P = A + 0.1b  
If Δt = 123.789 → P = A + 123.789b

Yes — literally **just adding vectors**.

---

# 🧠 2. Why this works (low-level explanation)

Imagine A is a memory address (not literally, but just imagine):

```
A = [Ax, Ay, Az]
b = [bx, by, bz]
```

Then:

```
P(t) = [
    Ax + t * bx,
    Ay + t * by,
    Az + t * bz
]
```

It's nothing but adding three floats.

The CPU is basically doing this:

```
mul b, t
add A, (b*t)
```

No loops  
No physics  
No integration  
Nothing hardcore

This is why ray tracing is so elegant.

---
# 🎯 4. But how do we _actually_ use it?

We never “animate” the ray by increasing t.  
Instead:

👉 We **solve** for the t where the ray hits an object.  
👉 That tells us _where_ on the ray the collision happens.

---

# 🧨 5. Mind-blowing fact

A ray tracer **never** simulates the ray moving.

It just:

1. Computes the parameter t where something happens
    
2. Uses vector addition to jump directly to that point
    

The ray equation is like a _teleporter_, not a _walking animation_.

---

# 🎥 Building the Camera Step-by-Step

A camera in ray tracing isn’t a real camera.  
It’s just:

- A point in space (the camera center) generally(0,0,0)
    
- A rectangle floating in front of it (the viewport)
    
- A bunch of tiny squares on that rectangle (pixels)
    
- Rays fired from the camera to the middle of each pixel

---

# 🎥 **1. Camera, Viewport, Pixel Grid — Conceptual Overview**

![Image](https://raytracing.github.io/images/fig-1.03-cam-geom.jpg?utm_source=chatgpt.com)

![Image](https://img2.quasarzone.co.kr/img/data/img/editor/1809/1809___1275788209.png?utm_source=chatgpt.com)

![Image](https://www.scratchapixel.com/images/introduction-to-ray-tracing/lightingnoshadow.gif?utm_source=chatgpt.com)

![Image](https://slideplayer.com/slide/14084485/86/images/14/Pixel%2BCalculation%2BCoordinate%2B%28in%2Bu%2Cv%2Cn%2Bspace%29%2Bof%2Bupper%2Bleft%2Bpixel%2Bcenter%2B%3D%2BThen%2Bback%2Boff%2Bhalf%2Ba%2Bpixel%2Bwidth%2Band%2Bheight%2Bto%2Bcompute%2Bpixel%2Bcenter..jpg?utm_source=chatgpt.com)

---

## 📌 **Camera**

- A point in 3D space (usually at `(0,0,0)`).
    
- It looks **toward −Z** in a right-handed coordinate system.
    
- All rays originate from this point.
    

---

## 📌 **Viewport**

Think of the viewport as:

> **A rectangular window floating in front of the camera, representing the entire field of view.**

It is:

- Placed at `z = -focal_length`
    
- A physical size in world-space
    
- Divided into pixels (sub-rectangles)
    

### Viewport size

```cpp
viewport_height = 2.0
viewport_width  = viewport_height * aspect_ratio
```

### Key idea

Viewport size determines **FOV**,  
Image resolution only determines **detail**.

---

# 🧭 **2. Viewport Axes (viewport_u & viewport_v)**

## 🎯 **viewport_u**

- 3D vector pointing **right** across the viewport
    
- Size = viewport width
    
- Example:
    
    ```
    viewport_u = (viewport_width, 0, 0)
    ```
    

## 🎯 **viewport_v**

- 3D vector pointing **DOWN** across the viewport
    
- Yes: DOWN = negative Y
    
- Why?
    
    - Image pixel rows increase downward
        
    - But world Y increases upward
        
    - So we flip sign to synchronize them
        
- Example:
    
    ```
    viewport_v = (0, -viewport_height, 0)
    ```
    

---

# 🧱 **3. World Coordinates vs Image Coordinates**

## 🌍 **World Coordinates**

- Used to define actual 3D positions.
    
- +X → right
    
- +Y → up
    
- −Z → forward
    
- Origin = camera center
    

## 🖼️ **Image (Pixel) Coordinates**

- Used for looping through pixels:
    
    ```
    i = 0 → width-1
    j = 0 → height-1
    ```
    
- Pixel (0,0) = **top-left**
    
- Rows increase **downward**
    

## 🧨 Why we need viewport_v negative?

Because:

- Image j-direction = downward
    
- World +Y = upward
    

So we sync them by defining:

```
viewport_v = (0, -H, 0)
```

This ensures pixel rows map correctly onto the viewport.

---

# 🔬 **4. Pixel Spacing (pixel_delta_u, pixel_delta_v)**

These represent the **world-space width & height of one pixel**.

```
pixel_delta_u = viewport_u / image_width
pixel_delta_v = viewport_v / image_height
```

Meaning:

- Move 1 pixel right → add pixel_delta_u
    
- Move 1 pixel down → add pixel_delta_v
    

Each pixel is a tiny rectangle on the viewport.

### Does entire pixel get same color?

✔ **Yes in Chapter 4.**  
We fire **one ray per pixel** → entire pixel = same color.  
(Antialiasing later fires many rays/pixel.)

---

# 🎯 **5. Computing viewport_upper_left**

### Formula:

```cpp
viewport_upper_left =
      camera_center
    - vec3(0,0,focal_length)
    - viewport_u/2
    - viewport_v/2;
```

## 💡 Intuition

### Step 1 → Move from camera to viewport plane

```
camera_center - (0,0,focal_length)
```

### Step 2 → Move LEFT by half-width

```
- viewport_u/2
```

### Step 3 → Move UP by half-height

```
- viewport_v/2
```

⚡ Combine all → You land at the **top-left corner of the viewport**.

---

# 🎯 **6. Computing pixel00_loc (center of first pixel)**

### Formula:

```cpp
pixel00_loc = viewport_upper_left
            + 0.5 * (pixel_delta_u + pixel_delta_v);
```

## 💡 Intuition

- The viewport corner is the _outer_ edge of the screen.
    
- Pixel centers lie **half a pixel inward**.
    

So we move:

- half pixel right
    
- half pixel down
    

That gives the exact **center of pixel (0,0)**.

---

# 🔍 **7. Final Diagram (ASCII)**

```
                   +Y (up)
                     ↑
                     |
              UL (viewport upper-left)
                     ●
                     |\
                     | \
                     |  \  half pixel right (0.5 * delta_u)
                     |   \
                     |    ● pixel00_loc (center)
                     |
camera ●-------------+-----------------------> +X
(0,0,0)              |
                     v
                    -Z (camera looks here)
```

---

# 🧠 **8. Key Takeaways (Obsidian TL;DR)**

- **Viewport = physical FOV plane in front of camera.**
    
- **Pixel grid subdivides the viewport.**
    
- **viewport_u & viewport_v = world-space width/height directions.**
    
- **pixel deltas = size of 1 pixel on viewport.**
    
- **viewport_upper_left = corner of viewport.**
    
- **pixel00_loc = center of first pixel (top-left).**
    
- **Rays fire from camera → pixel centers → world.**
    

---


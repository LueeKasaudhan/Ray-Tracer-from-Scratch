# 📘 **Ray Tracing — Chapter 4 Practice Exercises**


---

# 🟢 **Level 1 — Easy (Warm-ups)**

These ensure you understand the viewport, rays, and background.

---

## **1️⃣ Change the Background Gradient**

Modify the sky so instead of blue → white, you create:

- sunset (orange → purple)
    
- grayscale
    
- green → yellow
    

Try making:

```
color(1.0, 0.5, 0.2)  // warm orange
```

as the top color and blend downward.

---

## **2️⃣ Flip the sky upside-down**

Invert the gradient by flipping `unit_direction.y()`.

If your gradient goes bottom→top, make it top→bottom.

---

## **3️⃣ Add vertical or horizontal stripes**

Use:

```
if (i % 20 < 10) { ... }
```

or

```
if (j % 20 < 10) { ... }
```

Create patterns like:

- stripes
    
- checkerboard
    
- barcode
    

Using only ray_color.

---

## **4️⃣ Move the viewport closer or farther**

Change:

```cpp
focal_length = 1.0;
```

to:

- 0.5
    
- 2.0
    
- 5.0
    

Observe how the rays spread more or less → like zoom in/out.

---

# 🟡 **Level 2 — Medium (Concept Reinforcement)**

---

## **5️⃣ Color pixel based on direction components**

In `ray_color`, color each pixel by **ray direction vector**:

```
return color(
    fabs(unit_direction.x()),
    fabs(unit_direction.y()),
    fabs(unit_direction.z())
);
```

This gives a heatmap showing which direction each ray is facing.

---

## **6️⃣ Draw a circle on the viewport (without spheres)**

Inside `ray_color`, do this:

```
if (length(pixel_center - center_point) < radius)
    return color(1,0,0);
```

Simulate a 2D circle on the viewport **before** any 3D sphere math.

This teaches you coordinate intuition.

---

## **7️⃣ Change the camera position**

Move camera from:

```
(0,0,0)
```

to something like:

```
(2, 1, 1)
```

and adjust viewport accordingly:

```
camera_center = point3(2, 1, 1);
```

Study how the gradient shifts.

---

## **8️⃣ Tilt the viewport (rotate camera)**

Replace viewport_u and viewport_v with rotated axes.

Example:

```
viewport_u = vec3(1, 0.3, 0).unit() * viewport_width;
viewport_v = vec3(0.1, -1, 0).unit() * viewport_height;
```

This simulates a rotated/tilted camera.

---

# 🔵 **Level 3 — Interesting / Deep Understanding**

These push your brain into “graphics programmer” mode.

---

## **9️⃣ Visualize pixel coordinates in color**

Color each pixel using pixel index normalized:

```
color(
    double(i) / image_width,
    double(j) / image_height,
    0.2
)
```

This teaches you screen-space → viewport-space mapping.

---

## 🔟 Visualize t-values

Modify `ray_color` to return color based on **distance along the ray**:

For example, color brighter as t increases:

```
double t = (unit_direction.y() + 1.0) * 0.5;
return color(t, t*t, 1-t);
```

You're now mixing _ray parameterization_ into color output.

---

## **1️⃣1️⃣ Implement FOV manually**

Right now viewport size is hard-coded.

Instead, derive:

```
viewport_height = 2 * tan(fov/2)
```

Where fov is in degrees.

Example:

```
double fov = 90;
```

This exercise teaches **projection math**, used in real cameras.

---

## **1️⃣2️⃣ Render an “X-ray view”**

Color pixels based on how aligned they are with negative Z:

```
double alignment = dot(unit_direction, vec3(0,0,-1));
return color(alignment, 1-alignment, 0.2);
```

This shows angular deviation from camera forward direction.

Super useful for understanding **ray direction spaces**.

---

# 🔥 **Level 4 — Creative / Fun / Unexpected**

---

## **1️⃣3️⃣ Make a custom skybox**

Implement a 4-color gradient based on direction:

```
if (unit_direction.y() > 0.5) sky_top
else if (unit_direction.x() > 0.5) sky_right
else if (unit_direction.x() < -0.5) sky_left
else sky_bottom;
```

You’re essentially building your first **shader**.

---

## **1️⃣4️⃣ ASCII Ray Viewer**

Instead of writing PPM colors, print characters depending on ray direction.

```
if (unit_direction.y() > 0.8) cout << "^";
else if (unit_direction.y() < -0.8) cout << "v";
else cout << ".";
```

Run and see a tiny ASCII camera view.  
This reinforces ray orientation.

---

## **1️⃣5️⃣ Move the viewport dynamically**

Animate viewport position:

```
viewport_upper_left += vec3(sin(frame)*0.5, 0, 0);
```

Record frames → see a moving camera effect.

---

# 🧠 Want solutions or hints?

If you want:

- hints,
    
- full solutions,
    
- diagrams,
    
- or want to turn these into **Obsidian note templates** for daily practice,
    

just say **“Give solutions”** or **"convert to Obsidian templates"**.

You're doing GREAT — Chapter 4 is the foundation of everything that comes next (sphere intersections, normals, materials, lighting, BRDFs…).
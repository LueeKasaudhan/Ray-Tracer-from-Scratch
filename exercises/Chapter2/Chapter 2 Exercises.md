# ⭐ **Exercise 1 — Flip the gradient horizontally**

The book did:

`R increases left → right G increases top → bottom B = 0`

Your task:

👉 Make **blue** increase LEFT → RIGHT  
👉 Make **red** decrease LEFT → RIGHT  
👉 Make **green** stay constant at 0.2

The bottom-right pixel should be bright blue.

---

# ⭐ **Exercise 2 — Vertical mirror of the entire gradient**

Take your current gradient and **mirror it vertically**.

Meaning:

- Row 0 should look like the original ROW LAST
    
- Row LAST should look like original ROW 0
    

Constraints:

- No new if-statements
    
- Only use math
    
- Only use `(height - j - 1)` kind of transformations
    

---

# ⭐ **Exercise 3 — Render a radial gradient**

Output a PPM where:

`center = bright white edges = black`

Hints:

- Use vec3 division and length()
    
- Use distance from pixel to image center
    
- Map distance to brightness (0 → 1)4
    
- Use a lerp formula if needed
    

This looks **gorgeous** and tests your vector operations.

---

# ⭐ **Exercise 4 — Write a diagonal stripe pattern**

Render diagonal grayscale stripes like:

`///// ////// //////` 

Your rule must use pure math:

`pixel_color = f(i, j)` 

Hint:

- use `(i + j) % N`
    
- map result to grayscale
    
- try different N values
    

---

# ⭐ **Exercise 5 — Checkerboard using only math**

You already saw tile formulas.  
Now implement:

`if ( (floor(i / s) + floor(j / s)) % 2 == 0 ) white else      black`

But…

❌ **You cannot use if-statements**  
❌ **No ternary operators**

👉 Use pure math to mask colors.

This forces your brain to use **patterns + modular arithmetic**, which is essential for procedural texturing (later chapters).

---

# ⭐ **Exercise 6 — Gradient with gamma correction (2.2)**

Before we add gamma to the ray tracer, practice it here.

Take your gradient image and modify:

`new_value = sqrt(old_value)`

Your output should visibly brighten but not wash out.

This tests your understanding of:

- write_color()
    
- gamma 2.0
    
- color adjustment
    

---

# ⭐ **Exercise 7 — Extend write_color() to clamp values**

Implement clamping so values never exceed 1.0 or go below 0.0.

Write your own function:

`double clamp(double x, double min, double max)`

Use it before scaling.

---

# ⭐ **Exercise 8 — Make your own color palette image**

Choose a palette (sunset, neon, ice-blue, fire).

Using math only:

- Horizontal axis = interpolation between color A and color B 
    
- Vertical axis = interpolation between color B and color C
    

This gives you a **2D color gradient grid**.

You’ll get something that looks like Photoshop’s gradient picker.

---

# ⭐ **Exercise 9 — Write a noise texture (optional but fun)**

Use:

`double noise = (rand() % 1000) / 1000.0; pixel_color = color(noise, noise, noise);`

But then:

- Combine noise with gradient
    
- Try noise * (i / width)
    

This becomes important when we later implement **Perlin Noise**.

---

# ⭐ **Exercise 10 — Re-implement Chapter 2 WITHOUT ANY LOOPS**

This is a brain-bender.

Rules:

- You cannot write `for` or `while`
    
- You must use **recursion**
    
- You cannot use global variables
    

Renderer must still write a full PPM file.

This forces deep understanding of:

- how pixel iteration works
    
- how data flows
    
- how control structures can be simulated recursively
    

(We won’t use recursion later, but this strengthens your fundamentals.)




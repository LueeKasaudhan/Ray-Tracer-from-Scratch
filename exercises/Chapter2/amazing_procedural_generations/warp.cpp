#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// -------------------------------------
// 1. Hash-based pseudo-random gradient
// -------------------------------------
float hash2(int x, int y) {
    uint32_t h = x * 0x1f1f1f1f ^ y * 0x5f356495;
    h = (h ^ (h >> 15)) * 0x85ebca6b;
    h = (h ^ (h >> 13)) * 0xc2b2ae35;
    return (h & 0xffffff) / float(0xffffff);
}

// -------------------------------------
// 2. Smooth noise interpolation
// -------------------------------------
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

float smooth(float t) {
    return t * t * (3 - 2 * t);
}

float noise(float x, float y) {
    int ix = int(floor(x));
    int iy = int(floor(y));

    float fx = smooth(x - ix);
    float fy = smooth(y - iy);

    float v00 = hash2(ix,     iy);
    float v10 = hash2(ix + 1, iy);
    float v01 = hash2(ix,     iy + 1);
    float v11 = hash2(ix + 1, iy + 1);

    return lerp(
        lerp(v00, v10, fx),
        lerp(v01, v11, fx),
        fy
    );
}

// -------------------------------------
// 3. Domain Warp
// -------------------------------------
float domain_warp(float x, float y, float strength) {
    float nx = x + noise(x*0.5, y*0.5) * strength;
    float ny = y + noise(x*0.5 + 100, y*0.5 + 100) * strength;
    return noise(nx, ny);
}

// -------------------------------------
// 4. Fake lighting
// -------------------------------------
float shade(float x, float y) {
    float eps = 0.5;
    float h  = domain_warp(x,     y,     40);
    float hx = domain_warp(x+eps, y,     40);
    float hy = domain_warp(x,     y+eps, 40);

    float dx = hx - h;
    float dy = hy - h;

    float light = 0.5 + 0.5 * (dx * -0.7 + dy * -0.7);
    return max(0.0f, min(1.0f, light));
}

// -------------------------------------
// 5. Main
// -------------------------------------
int main() {
    int width = 600;
    int height = 600;

    ofstream out("domain_warp.ppm");
    out << "P3\n" << width << " " << height << "\n255\n";

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {

            float x = i * 0.02f;
            float y = j * 0.02f;

            float value = domain_warp(x, y, 40);
            float shaded = shade(x, y);

            int r = int(255 * shaded * (0.6 + value * 0.4));
            int g = int(255 * shaded * (0.2 + value * 0.8));
            int b = int(255 * shaded * value);

            out << r << " " << g << " " << b << " ";
        }
        out << "\n";
    }

    out.close();
    cout << "Output saved → domain_warp.ppm\n";

    return 0;
}

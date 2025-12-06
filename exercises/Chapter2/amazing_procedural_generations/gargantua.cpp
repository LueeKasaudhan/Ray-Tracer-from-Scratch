#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Smoothstep (glsl style)
float smoothstep(float a, float b, float x) {
    x = (x - a) / (b - a);
    x = fmax(0.0f, fmin(1.0f, x));
    return x * x * (3 - 2 * x);
}

// Simple noise
float hash2(float x, float y) {
    int xi = int(x * 15731) ^ int(y * 789221);
    xi = (xi << 13) ^ xi;
    return (1.0 - ((xi * (xi * xi * 15731 + 789221) + 1376312589)
          & 0x7fffffff) / 1073741824.0);
}

// Fake turbulence
float turbulence(float x, float y) {
    float t = 0;
    float freq = 1.0;
    float amp = 1.0;

    for (int i = 0; i < 5; i++) {
        t += fabs(hash2(x * freq, y * freq)) * amp;
        freq *= 2.0;
        amp *= 0.5;
    }
    return t;
}

int main() {
    int W = 800, H = 800;
    float cx = W / 2.0;
    float cy = H / 2.0;

    ofstream out("gargantua.ppm");
    out << "P3\n" << W << " " << H << "\n255\n";

    for (int j = 0; j < H; j++) {
        for (int i = 0; i < W; i++) {

            float x = (i - cx) / cx;
            float y = (j - cy) / cy;

            float r = sqrt(x * x + y * y);
            float angle = atan2(y, x);

            // Event horizon (radius of black hole)
            float hole_r = 0.22;

            // Photon sphere (glowing thin ring)
            float photon_r = 0.28;
            float photon_ring = exp(-pow((r - photon_r) * 25.0, 2));

            // Accretion disk plane
            float inclination = 0.3;  // tilt like Interstellar
            float disk_y = y + inclination * (x);

            // Disk radius region
            float disk_r_min = 0.3;
            float disk_r_max = 0.9;

            // Disk brightness
            float disk_mask = smoothstep(disk_r_min, disk_r_min + 0.02, r) *
                              (1.0 - smoothstep(disk_r_max - 0.02, disk_r_max, r));

            // Disk turbulence
            float turb = turbulence(x * 3, y * 3);

            // Doppler shift (one side blue, one side red)
            float doppler = 0.5 + 0.5 * cos(angle);

            // Disk base color
            float disk = turb * disk_mask;

            // Emission boosted near the hole
            disk *= pow(1.0 - r, 2) * 4.0;

            // Apply doppler tint
            float R = disk * (1.2 - doppler * 0.7);
            float G = disk * (0.7 + doppler * 0.3);
            float B = disk * (0.2 + doppler * 0.8);

            // Add photon ring
            R += photon_ring * 2.0;
            G += photon_ring * 1.2;
            B += photon_ring * 0.5;

            // Event horizon = pure black
            if (r < hole_r) {
                R = G = B = 0;
            }

            // Clamp
            R = fmin(1.0f, fmax(0.0f, R));
            G = fmin(1.0f, fmax(0.0f, G));
            B = fmin(1.0f, fmax(0.0f, B));

            out << int(R * 255) << " "
                << int(G * 255) << " "
                << int(B * 255) << " ";
        }
        out << "\n";
    }

    out.close();
    cout << "Saved → gargantua.ppm\n";
}

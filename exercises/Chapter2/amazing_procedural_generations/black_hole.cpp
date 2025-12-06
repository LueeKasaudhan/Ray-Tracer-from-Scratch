#include <iostream>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

float noise(float x, float y) {
    // Simple hash noise
    int xi = int(x * 15731) ^ int(y * 789221);
    xi = (xi << 13) ^ xi;
    return (1.0 - ((xi * (xi * xi * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

float swirl(float angle, float r) {
    return angle + 0.4 * exp(-r * 3.0);  // swirl effect falls off outward
}
float smoothstep(float edge0, float edge1, float x) {
    // Scale, bias and saturate x to 0..1
    x = (x - edge0) / (edge1 - edge0);
    x = max(0.0f, min(1.0f, x));
    // Evaluate polynomial (GLSL smoothstep)
    return x * x * (3 - 2*x);
}


int main() {
    int W = 600, H = 600;
    float cx = W / 2.0;
    float cy = H / 2.0;

    ofstream out("blackhole.ppm");
    out << "P3\n" << W << " " << H << "\n255\n";

    for (int j = 0; j < H; j++) {
        for (int i = 0; i < W; i++) {

            float x = (i - cx) / cx;   // normalize to [-1,1]
            float y = (j - cy) / cy;

            float r = sqrt(x*x + y*y);
            float angle = atan2(y, x);

            // MASSIVE SWIRL
            float warped_angle = swirl(angle, r);
            float nx = r * cos(warped_angle) * 3.0;
            float ny = r * sin(warped_angle) * 3.0;

            // swirling noise for the accretion disk
            float disk = fabs(noise(nx, ny));

            // Accretion disk glow curve (bright at mid-radii)
            float glow = exp(-pow((r - 0.5) * 4.0, 2));

            // black hole event horizon
            float hole = smoothstep(0.1, 0.2, r);  // 0 inside horizon

            float brightness = disk * glow * hole;

            // Fake gravitational lensing tint
            float red   = brightness * (1.2 - r * 0.4);
            float green = brightness * (0.8 + r * 0.2);
            float blue  = brightness * (0.5 + r * 0.5);

            int R = int(255 * max(0.0f, min(1.0f, red)));
            int G = int(255 * max(0.0f, min(1.0f, green)));
            int B = int(255 * max(0.0f, min(1.0f, blue)));

            // Event horizon (pure black)
            if (r < 0.18) { R = G = B = 0; }

            out << R << " " << G << " " << B << " ";
        }
        out << "\n";
    }

    out.close();
    cout << "Black hole image saved → blackhole.ppm\n";
}

#include <bits/stdc++.h>

#include <chrono>
#include <thread>
using namespace std;

const int screen_width = 100;
const int screen_height = 50;

const float theta_spacing = 0.07f;
const float phi_spacing = 0.02f;

const float R1 = 1;
const float R2 = 2;
const float K2 = 5;
const float PI = 3.14159265358979323846f;

float compute_K1() {
  return screen_width * K2 * 3 / (8 * (R1 + R2));
}

void render_frame(float A, float B) {
  static float K1 = compute_K1();

  float cosA = cos(A), sinA = sin(A);
  float cosB = cos(B), sinB = sin(B);

  char output[screen_height][screen_width];
  float zbuffer[screen_height][screen_width];

  // Initialize buffers
  for (int y = 0; y < screen_height; y++) {
    for (int x = 0; x < screen_width; x++) {
      output[y][x] = ' ';
      zbuffer[y][x] = 0;
    }
  }

  for (float theta = 0; theta < 2 * PI; theta += theta_spacing) {
    float costheta = cos(theta), sintheta = sin(theta);

    for (float phi = 0; phi < 2 * PI; phi += phi_spacing) {
      float cosphi = cos(phi), sinphi = sin(phi);

      float circlex = R2 + R1 * costheta;
      float circley = R1 * sintheta;

      float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;

      float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;

      float z = K2 + cosA * circlex * sinphi + circley * sinA;
      float ooz = 1 / z;

      int xp = (int)(screen_width / 2 + K1 * ooz * x);
      int yp = (int)(screen_height / 2 - K1 * ooz * y * 0.5);

      if (xp < 0 || xp >= screen_width || yp < 0 || yp >= screen_height)
        continue;

      float L = cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);

      if (L > 0 && ooz > zbuffer[yp][xp]) {
        zbuffer[yp][xp] = ooz;
        int luminance_index = (int)(L * 8);
        const char luminance[] = ".,-~:;=!*#$@";
        output[yp][xp] = luminance[luminance_index];
      }
    }
  }

  printf("\x1b[H");  // move cursor to top-left

  for (int y = 0; y < screen_height; y++) {
    for (int x = 0; x < screen_width; x++) {
      putchar(output[y][x]);
    }
    putchar('\n');
  }
}

int main() {
  float A = 0, B = 0;

  printf("\x1b[2J");    // clear screen
  printf("\x1b[?25l");  // hide cursor

  while (true) {
    render_frame(A, B);
    A += 0.04;
    B += 0.02;
    this_thread::sleep_for(chrono::milliseconds(30));
  }

  printf("\x1b[?25h");  // show cursor
  return 0;
}
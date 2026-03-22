#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

const int width = 100;
const int height = 70;

string render(float A, float B) {
  vector<char> buffer(width * height, ' ');
  vector<float> zbuffer(width * height, 0);

  float R1 = 1;
  float R2 = 2;
  float K2 = 5;
  float K1 = width * K2 * 3 / (8 * (R1 + R2));

  for (float theta = 0; theta < 2 * M_PI; theta += 0.07) {
    for (float phi = 0; phi < 2 * M_PI; phi += 0.02) {
      float cosA = cos(A), sinA = sin(A);
      float cosB = cos(B), sinB = sin(B);

      float costheta = cos(theta), sintheta = sin(theta);
      float cosphi = cos(phi), sinphi = sin(phi);

      float circlex = R2 + R1 * costheta;
      float circley = R1 * sintheta;

      float x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;

      float y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;

      float z = K2 + cosA * circlex * sinphi + circley * sinA;
      float ooz = 1 / z;

      int xp = (int)(width / 2 + K1 * ooz * x);
      int yp = (int)(height / 2 - K1 * ooz * y * 0.5);

      if (xp < 0 || xp >= width || yp < 0 || yp >= height)
        continue;

      int idx = xp + yp * width;

      float L = cosphi * costheta * sinB - cosA * costheta * sinphi - sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);

      if (L > 0 && ooz > zbuffer[idx]) {
        zbuffer[idx] = ooz;
        const char luminance[] = ".,-~:;=!*#$@";
        buffer[idx] = luminance[(int)(L * 8)];
      }
    }
  }

  // Convert buffer into string frame
  string frame;
  frame.reserve(width * height + height);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      frame += buffer[x + y * width];
    }
    frame += '\n';
  }

  return frame;
}

int main() {
  float A = 0, B = 0;

  cout << "\x1b[2J";  // clear screen

  while (true) {
    cout << "\x1b[H";  // move cursor to top
    cout << render(A, B);

    A += 0.04;
    B += 0.02;

    this_thread::sleep_for(chrono::milliseconds(30));
  }

  return 0;
}
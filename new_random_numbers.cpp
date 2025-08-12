#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  int n = 10;
  int random_value = rand() % n;

  cout << "Random Integer";
  bug(random_value);

  cout << "Using new c++11 random feature  " << endl;

  mt19937 gen(static_cast<unsigned int>(time(0)));  // Seed RNG
  uniform_int_distribution<int> dist(10, 50);       // Range [10, 50]

  int r = dist(gen);

  cout << "Random integer in [10, 50] = " << r << endl;

  // random_device rd;
  // mt19937 gen(rd());
  mt19937 gen1(static_cast<unsigned int>(time(0)));
  uniform_real_distribution<double> dist1(0.0, 0.01);

  double double_random_value = dist1(gen1);

  bug(double_random_value);

  double n2 = 0.01;
  double r22 = (double)rand() / RAND_MAX * n2;

  cout << "Random double: " << r22 << endl;

  return 0;
}
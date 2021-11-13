#include<iostream>
using namespace std;
class Sample {
private:
  int a, b;
public:
  Sample() : a(0), b(0) { }
  Sample& operator()(int x, int y);
  void display() {cout << "a = " << a << ", b = " << b; }
};
Sample& Sample::operator()(int x, int y)
{
    b = x;
    a = y;
    return *this;
}
int main()
{
  Sample s;
  s(10, 5);
  s.display();
  return 0;
}

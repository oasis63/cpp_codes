#include<iostream>
using namespace std; 
class ThisPointer
{
private:
  int x;
public:
  ThisPointer() {x = 100;}
  void deletion()  { delete this; }
  void display() { cout << "x = " << x; }
}; 
int main()
{
  ThisPointer tp;
  tp.deletion();
  tp.display();
  return 0;
} 
#include <iostream>
using namespace std;
class Test
{
protected:
    int x;
public:
    Test() {x = 0;}
    friend void show();
}; 
class TestDerived: public Test
{
public:
    B() : y (0) {}
private:
    int y;
}; 
void show()
{
    Test a;
    TestDerived b;
    cout << "The default value of Test::x = " << a.x << " ";
    cout << "The default value of TestDerived::y = " << b.y;
}
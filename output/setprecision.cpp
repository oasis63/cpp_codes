#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double d = 122.345;

    cout << fixed;
    cout << setprecision(2);
    cout << d;
}

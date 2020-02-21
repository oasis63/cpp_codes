#include<iostream>
using namespace std;
int a = 100;
void scope()
{
    int a = 50;
    {
        int a = 30;
        cout << ::a << endl;
    }
}
int main()
{
    scope();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define pi 3.14
#define e 2.718

int main()
{
    int n;
    cin>>n;

    int f = ceil((sqrt(2*pi*n))*pow((n/e),n));

    cout<<f<<endl;
}

//n!≈√2πn⋅(n/e)^n;  
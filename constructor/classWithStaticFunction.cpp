#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    static int add(int a,int b)
    {
        return (a+b);
    }
};

int main()
{

    cout<<Test::add(4,3)<<endl;
}

// Static functions can be called without making the class's object

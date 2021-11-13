#include <bits/stdc++.h>
using namespace std;


namespace ns
{
    void display();
    class Test;
}

void ns::display()
{
    cout<<"ns::display()"<<endl;
}

class ns::Test
{
    public:
        void display()
        {
            cout<<"ns::Test::display()"<<endl;
        }

};

using namespace ns;

int main()
{

    display();
    Test obj;
    obj.display();
}

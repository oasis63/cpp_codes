#include <bits/stdc++.h>
using namespace std;

class Detail
{
   private:
    string name;
    int id;
   public:
    Detail()
    {
        name =  "Rajesh";
        id=404;
    }

    Detail(int i , string n)
    {

        id=i;
        name=n;
    }

    void show()
    {

        cout<<name<<endl;
        cout<<id<<endl;
    }

};


// pass by reference
void swap(Detail& a , Detail& b)
{
    Detail temp = a;
    a=b;
    b=temp;

}

int main()
{
    Detail d = Detail();

    Detail d2 = Detail(24,"Cha");

    // swapping the two objects
    swap(d,d2);

    d2.show();
    d.show();

   return 0 ;
}

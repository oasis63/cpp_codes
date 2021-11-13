// Work always bring something. But does not contain nothig.
#include<iostream>
using namespace std;


int x ,y;
class num
{
  int x;
  public:
        void setx()
        {
          cout<<"\nEnter a number\n";
          cin>>x;
          cout<<"y = ";
          cin>>y;
          
          cout<<"x = ";
          cin>>::x;
        }
        void showx()
        {
          cout<<"Local x = "<<x<<endl;
          cout<<"Global Y = "<<y<<endl;
          cout<<"Global X = "<<::x<<endl;
        }
};
int main()
{
  num n;
  n.setx();
  
  n.showx();
}       

/* ::x represents the Global x
  num::x represents the x from the class */

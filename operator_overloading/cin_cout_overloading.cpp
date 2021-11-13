//operator overloading for "insertion"(<<) and "extraction"(>>)
#include<iostream>
using namespace std;

class complex
{
  private:
        int a,b;
  public:
        friend ostream& operator<<(ostream& ,complex);
        friend istream& operator>>(istream&, complex&);
};

ostream& operator<<(ostream &dout, complex c)
{
  cout<<"\na="<<c.a<<endl<<"\nb="<<c.b<<endl;
  return(dout);
}
istream& operator>>(istream &din , complex &c)
{
  cin>>c.a>>c.b;
   return(din);
}
int main()
{
  complex c1;
  
  cout<<"\nEnter a complex number \n";
  cin>>c1;  // operator>>(cin,c1);
  
  cout<<"\nYour entered complex number \n";
  cout<<c1; // opertor<<(cout,c1);
  
  return 0;
  
}  

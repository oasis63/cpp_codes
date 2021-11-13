/*function overloading. It uses the concept of polymorphism */
#include<iostream>
#include<cmath>
using namespace std;
float area(float a,float b)
{
  return(a*b);
}
float area(float a)
{
  return(a*a);
}
float area(float a,float b,float c)
{
  float ar,s;
  s=(a+b+c)/2;
  
  ar=sqrt(s*(s-a)*(s-b)*(s-c));
  
  return ar;
}
int main()
{
  float a,b,c;
  cout<<"\nEnter the lenght of sides of a triangle\n";
  cin>>a>>b>>c;
 
  cout<<"Area of the triangle: "<<area(a,b,c)<<endl;
  
  cout<<"\nEnter the length of sides of the rectangle\n";
  cin>>a>>b;
  
  cout<<"Area of the rectangle: "<<area(a,b)<<endl;
  
  cout<<"\nEnter the side lenght of the square\n"<<endl;
  cin>>a;
  
  cout<<"\nArea of the square: "<<area(a)<<endl;
}
  

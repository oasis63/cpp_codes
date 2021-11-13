#include<iostream>
#include<cstring>
using namespace std;

struct book
{
  int id;
  char name[20];
  float price;
  
  void print()
  {
  cout<<endl<<"Name: "<<name<<endl;
  cout<<"Id: "<<id<<endl;
  cout<<"Price: "<<price<<endl;
  }
  
  book input()
 {  
  cout<<"enter the id of the book\n";
  cin>>id;
  cout<<"\nEnter the name of the book\n";
  cin>>name;
  
  cout<<"\nEnter the price of the book\n";
  cin>>price;
  }
};


int main()
{
  book b;
  b.input();
  b.print();
}

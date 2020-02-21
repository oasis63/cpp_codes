//video no 20 from shukla
#include<iostream>
using namespace std;


template <class X>
class list
{
  private:
      struct Block
      {
        int capacity;
        X *arr;
      };
      
      Block *s;
   
  public:
     
     
     list(int capacity)                  //constructor
     {
       s =  new Block;
       s->capacity=capacity;
       s->arr=new X[s->capacity]; 
     }
     
     void addElem(int index,X data)
     {
       if(index>=0 && index<s->capacity)
        s->arr[index]=data;
       else
        cout<<"\nNo free memory\n";
     }
     
     void viewList()
     {
        int i;
        for(i=0;i<=s->capacity-1;i++)
        {
           cout<<" "<<s->arr[i];
        }
     }
     
     ~list()
     {
       cout<<"\nDestructing the list\n";
     }
};

int main()
{ 
   list <int> l(5);
   
   int i,j;
   
  cout<<"\nEnter 5 elements\n";
   
   for(i=0;i<5;i++)
   {
      cin>>j;
      l.addElem(i,j);
   }
   
   l.viewList();
   
   return 0;
}
   
  
     

//video no 20 from shukla
#include<iostream>
using namespace std;

class list
{
  private:
      struct Block
      {
        int capacity;
        int *arr;
      };
      
      Block *s;
   
  public:
     
     
     list(int capacity)                  //constructor
     {
       s =  new Block;
       s->capacity=capacity;
       s->arr=new int[s->capacity]; 
     }
     
     void addElem(int index,int data)
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
   list l(5);
   
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
   
  
     

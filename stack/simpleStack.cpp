//implementing stack using arrary in class of c++
#include<iostream>
using namespace std;

class stack
{
  private:
        struct block
        {
          int top;
          int capacity;
          int *arr;
        };
        
        block *s;
  public:
        //constructor for the stack 
        stack(int size)
        {
          s=new block;
          s->top=-1;
          s->capacity=size;
          s->arr= new int[size];
        }
        
        int isFull()
        {
          if(s->top==s->capacity-1)
            return 1;
          return 0;
        }
        
        int isEmpty()
        {
           if(s->top==-1)
             return 1;
           return 0;
        }
        
        void push(int data)
        {
          if(!isFull())
          {  
            s->top ++;
            s->arr[s->top]=data;
          }
          else
          {
            cout<<"\nStack is Full\n";
          }
        }
        
        int pop()
        {
          int t;
          
          if(!isEmpty())
          {
             t=s->arr[s->top];
             return t;
          }
          else
          {
            cout<<"\nStack is empty\n";
          }
        }
        
        int topElem()
        {
          return s->arr[s->top];
        }
        
        void display()
        {
          int i=0;
          for(i=0;i<=s->top;i++)
          {
            cout<<" "<<s->arr[i];
          }
        }
        
        void remove()
        {
          if(s)
          {
             if(s->arr)
              delete [] s->arr;
            delete s;
          }
        }
        
        ~stack()
        {
          cout<<"\nDestructing the object\n";
        }
};

int main()
{
  int size;
  
  cout<<"\nEnter the size of the stack\n";
  cin>>size;
  
  stack s(size);
  
  int i,j;
  
  cout<<"Enter "<<size<<" element\n";
  
  for(i=0;i<size;i++)
  { 
    cin>>j;
    s.push(j);
  }
  
  s.display();
  
  s.remove();
  
  cout<<endl;
  
  return 0;
}
          
          
        

//implementing stack using arrary in class of c++
#include<iostream>
using namespace std;

template <class X>
class stack
{
  private:
        struct block
        {
          int top;
          int capacity;
          X *arr;
        };
        
        block *s;
  public:
        //constructor for the stack
        stack(int size)
        {
          s=new block;
          s->top=-1;
          s->capacity=size;
          s->arr= new X[size];
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
        
        void push(X data)
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
        
        X pop()
        {
          X t;
          
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
        
        X topElem()
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
  
  stack <int>s(size);
  
  int i,j;
  
  cout<<"Enter "<<size<<" element\n";
  
  for(i=0;i<size;i++)
  { 
    cin>>j;
    s.push(j);
  }
  
  s.display();
  
  s.push(4);
  
  s.remove();
  
  cout<<endl;
  
  return 0;
}
          
          
        

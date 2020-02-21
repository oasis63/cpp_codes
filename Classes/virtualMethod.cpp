#include<iostream>
using namespace std; 
class BaseClass
{
public:
    virtual void display() { cout<<"From BaseClass "; }
}; 
class Derived: public BaseClass
{
public:
    void display() { cout<<"From DerivedClass "; }
}; 
int main(void)
{
    BaseClass *bp = new Derived;
    bp->BaseClass::display();  
    bp->display();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Parent{
public:
    void show(){
        cout<<"Parent Show Method"<<endl;
    }
    void disp(){
        cout<<"Parent disp method"<<endl;
    }
};

class Child : public Parent{
public:
    void show(){
        cout<<"Child Show Method"<<endl;
    }
    void disp(){
        cout<<"Child disp method"<<endl;
    }
     void message(){
        cout<<"Child message method"<<endl;
    }
};

int main(){
    Child c;
    Parent p ;

    Parent *p1;   // polymorphism
    p1 = &c;
    p1->show();
    //p1->message();   // cannot be accessed by Parent pointer
}

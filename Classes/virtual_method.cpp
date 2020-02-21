#include<bits/stdc++.h> 
using namespace std;   

/*
	Virtual functions are resolved late , at run time;
	So the base class pointer pointing to derived class object will
	call the derived method 

*/
   
class Base 
{ 
public: 
    void show() {
    	 cout<<" In Base \n"; 
 	} 

 	virtual void display(){      
 		cout<<"Base Display ()"<<endl;
 	}

}; 
   
class Derived: public Base 
{ 
public: 
    
    void show() { 
    	cout<<"In Derived \n"; 
    } 

    void display(){
    	cout<<"Child Display"<<endl;
    }

}; 
   
int main(void) 
{ 
    Base *bp = new Derived; 
    bp->show();  // RUN-TIME POLYMORPHISM 
    bp->display();
    return 0; 
} 

#include<iostream>
using namespace std;
class BaseClass {};
class DerivedClass: public BaseClass {};

int main(){

   DerivedClass d;
   try {
       throw d;
   }
   catch(BaseClass b) {
        cout<<"Caught BaseClass Exception ";
   }
   catch(DerivedClass d) {
        cout<<"Caught DerivedClass Exception ";
   }
   return 0;
}

// CPP program to illustrate 
// Implementation of erase() function 
#include <iostream> 
#include <vector> 
using namespace std; 
  
int main() 
{ 
    vector<int> myvector{ 1, 2, 3, 4, 5 }; 
    
    vector<int>::iterator it1, it2; 
  
    it1 = myvector.begin(); 
    it2 = myvector.end(); 
    it2--; 
    it2--; 
  
    myvector.erase(it1, it2); 
  
    // Printing the Vector 
    for (auto it = myvector.begin(); it != myvector.end(); ++it) 
        cout << ' ' << *it; 


    cout<<"\n\n----------------\n"<<endl;


    vector<int> myvector2{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
  
    for (auto i = myvector2.begin(); i != myvector2.end(); ++i) { 
        if (*i % 2 == 0) { 
            myvector2.erase(i); 
            i--; 
        } 
    } 
  
    // Printing the vector 
    for (auto it = myvector2.begin(); it != myvector2.end(); ++it) 
        cout << ' ' << *it; 



    return 0; 
} 
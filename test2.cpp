#include<bits/stdc++.h>
using namespace std;

int maxDivide(int a, int b) {

  while (a%b == 0) 
       a = a/b;  
  return a; 
}  

int main(){
    
    cout<<maxDivide(100,2)<<endl;

    return 0;
}
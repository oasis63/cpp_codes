#include<bits/stdc++.h>
using namespace std;

/*
Not sure about the solution
Reverify the code 

*/

int mmi(int a, int m){
    if(a==1)return 1;
    int e=m;
    int f=a;
    int x= 0;
    int y= 1;
    unsigned long long  u = 1;
    int v = 0;
    int q=0,r=0,c=0,d=0;

    while(f!=1){
        q = e/f; 
        r = e%f; 
        c = x- q*u; 
        d = y - q*v; 
        x = u; 
        y = v; 
        u = c; 
        v = d; 
        e = f; 
        f = r;
    }
    return (u+m)%m;
}

int main(){
  
  cout<<mmi(5,3)<<endl;

  return 0;
}
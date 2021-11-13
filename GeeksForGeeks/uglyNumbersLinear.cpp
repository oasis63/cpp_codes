#include<bits/stdc++.h>
using namespace std;

// Ugly numbers are numbers whose only prime factors are 2, 3 or 5

int maxDivide(int a, int b) {
  while (a%b == 0) 
       a = a/b;  
  return a; 
}  

bool isUglyNumber(int num){
    
    num = maxDivide(num,2);
    num = maxDivide(num,3);
    num = maxDivide(num,5);

    return num==1?true:false;
}


int nthUglyNumber(int n ){

    int i=1;
    int count = 1;

    while(n>count){
        i++;
        if(isUglyNumber(i))
            count++;
    }

    return i;
}


int main(){
    
    cout<<nthUglyNumber(150)<<endl;

    return 0;
}
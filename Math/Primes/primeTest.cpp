// prime number check 

#include <bits/stdc++.h>
using namespace std;

int prime(int n){

  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0)
        return 0;
  }
  return 1;
}

int main(){

  int n;cin>>n;
  if(prime(n))
    cout<<"Prime Number"<<endl;
  else
    cout<<"Not a prime"<<endl;
}
#include<bits/stdc++.h>
using namespace std;


vector<int> factorize(int n){
    vector<int>res;

    res.push_back(1);

    int t = sqrt(n);

    for(int i=2;i<=t;i++){
        while(n%i==0){
            res.push_back(i);
            n=n/i;
        }
    }

    if(n!=1)
        res.push_back(n);
    return res;
}


int main(){

   vector<int> v = factorize(36);

   for(int i : v){
        cout<<i<<" ";
   }

    cout<<endl;

    v = factorize(17);

   for(int i : v){
        cout<<i<<" ";
   }

}

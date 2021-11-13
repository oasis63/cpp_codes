#include<bits/stdc++.h>
using namespace std;

/*
Given a positive integer n represent it as a sum of maximum possible number of prime numbers.
*/

#define ll long long
#define SIZE  1000001
bool primes[SIZE];

set<ll> primeSet;

void setPrimes(){

    for(ll i=0;i<SIZE;i++){
        primes[i]=true;
    }

    primes[0]=false;
    primes[1]=false;

    for(ll i=2;i<=sqrt(SIZE);i++){

       if(primes[i]){
            for(ll j=i+i;j<SIZE;j+=i){
                primes[j]=false;
            }
       }
        
    } 

    for(ll i=0;i<SIZE;i++){
        if(primes[i]){
            primeSet.insert(i);
        }
    }

} 


int main(){
    
    setPrimes(); 

    int n;// = 6;
    cin>>n;
    vector<int> ans;

    for(auto itr : primeSet){
       
       while(n-itr >= 2 || n-itr ==  0){
            n -= itr;
            ans.push_back(itr);
       }

       if(n==0)
            break;
       
    }
     
    //cout<<n<<endl;
    n = ans.size();
    cout<<n<<endl;

    for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

/*

Sample I/O
--------------------------    
Input               Ouput
-------------------------
5                   2
                    2 3
------------------------
-------------------------
6                   3
                    2 2 2 
------------------------



*/
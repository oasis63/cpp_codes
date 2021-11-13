#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int

// number of bits

ull setCount(ull n){
    ull count=0;
    while(n){
        n=n&(n-1);
        count++;
    }

    return count;
}

int main(){

    ios_base::sync_with_stdio(false);

    int t;cin>>t;
    while(t--){
        ull n;cin>>n;

        if(n&1){ // odd input

            ull nxt = n+1;
            while(1){

                int btw = n^nxt;

                if(setCount(btw)==1){
                    cout<<nxt<<endl;
                    break;
                }

                nxt++;

            }

        }
        else{ // even input
            cout<<"Even"<<endl;
            n++;cout<<n<<endl;
        }
    }
}

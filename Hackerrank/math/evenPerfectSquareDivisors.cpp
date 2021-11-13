#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

ll gcd(ll a,ll b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void countDivisors(ll n){

    ll count = 1;
    ll evenPerfect = 0;

    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i){
                count++;

                if(i%2==0){
                    double r = sqrt(i);
                    ll rl = (ll)r;
                    double sb = r-(double)rl;

                    if(sb==0)
                        evenPerfect++;
                }

            }else{
                count+=2;
                if(i%2==0){
                    double r = sqrt(i);
                    ll rl = (ll)r;
                    double sb = r-(double)rl;

                    if(sb==0)
                        evenPerfect++;
                }

                if((n/i)%2==0){
                    double r = sqrt(n/i);
                    ll rl = (ll)r;
                    double sb = r-(double)rl;

                    if(sb==0)
                        evenPerfect++;
                }
            }
        }
    }


    if(evenPerfect==0){
        cout<<0<<endl;
    }else{

        // reduce to lowest fraction form  

        ll g = gcd(evenPerfect,count);
        evenPerfect = evenPerfect/g;
        count = count/g;
        
        cout<<evenPerfect<<"/";
        cout<<count<<endl;
        
    }
}

int main(){
   int tc;
   cin>>tc;
   ll n;
   while(tc--){
        cin>>n;
        if(n%2==1)   // odd numbers has always odd divisors 
            cout<<0<<endl;
        else
            countDivisors(n);
   }

    return 0;
}

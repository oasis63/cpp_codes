#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1000000007;


ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
// Returns LCM of array elements 
ll findlcm(vector<ll> arr, ll n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (ll i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
}

ll modExpo(ll a,ll n,ll m){
    if( n== 0)
        return 1;
    else if(n%2==0)
        return modExpo((a*a)%m,n/2,m);
    else
        return (a*(modExpo((a*a)%m,(n-1)/2,m)))%m;
}


ll modInverse(ll a,ll p){
    return modExpo(a,p-2,p);   // using fermat's Therorem 
}



int main(){
                
    /*
        Find  (a/b)%p   where p is a prime 
        Ex:- 
            (2/5)%3
    */  

    /*ll a,b,p;
    a=5;
    b=9;
    p=mod;

    ll res = (a%p)*modInverse(b,p);    

    cout<<res<<endl;*/

    ll tc;
    cin>>tc;

    ll n,k,m;

    for(ll ti;ti<tc;ti++){
        cin>>n>>k>>m;

        ll sum = 0;

        vector<ll> num;
        vector<ll> deno;

        ll steps = 1;

        bool win = true;

        ll ls = n-1; // loose odds 

        while(m-- > 0){
            if(n>k){
                n-=k;
            }else{
                ll  s = steps;

                ll nm = 1;
                ll dm = 1;

                while(s-- > 0){

                   if(n>k && m!=0){
                        n-=k;
                        // s++;
                        m--;
                        //cout<<"s: "<<s<<endl;
                    }

                    if(win){
                        nm *= 1;
                        dm *= n;
                        win = !win;
                        ls = n-1;
                    }else{
                        nm *= ls;
                        dm *= n;

                        n += k;
                        win = !win;
                    }

                }

                if(dm!=1){
                    num.push_back(nm);
                    deno.push_back(dm);
                    steps++;
                }
            }
        }


        ll len = num.size();

        /*for(ll i=0;i<len;i++){
            cout<<num[i]<<" ";
            cout<<deno[i]<<endl;
        }*/


        ll lcm = findlcm(deno,len);

        sum=0;

        for(ll i=0;i<len;i++){
            ll div = lcm/deno[i];
            num[i] *= div;
            sum += num[i];
        }


        ll g = gcd(sum,lcm);

        sum /= g;
        lcm /= g;


        ll a,b,p;
        a=sum;
        b=lcm;
        p=mod;


       /* cout<<"sum : "<<sum<<endl;
        cout<<"lcm : "<<lcm<<endl;*/

        ll res = (a%p)*modInverse(b,p);    

        cout<<res<<endl;
 

    }



    return 0;
}
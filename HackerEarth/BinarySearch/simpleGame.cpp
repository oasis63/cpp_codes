#include <bits/stdc++.h>
using namespace std;

#define ll long long

// strictly greater than key
ll  strictGreater(ll a[],ll n,ll key){
    ll l=0,r=n-1,mid;


    while(l<=r){
        mid=(l+r)/2;
      if(a[mid] <= key){
            if(a[mid+1] > key && (mid+1 < n)){
                break;
            }


            l=mid+1;

            if(l>=n){
               return 0;
            }

        }
        else{   // a[mid]  > key
            r=mid-1;
            if(r<0)
                return n;
        }
    }

    return (n-mid-1);

}

// strictly smaller than key
ll  strictSmaller(ll a[],ll n,ll key){
    ll l=0,r=n-1,mid;


    while(l<=r){
        mid=(l+r)/2;
      if(a[mid] >= key){
            if(a[mid-1] < key && (mid-1  >= 0) ){
                break;
            }

            r=mid-1;
        }
        else{   // a[mid]  < key
            l=mid+1;

            if(l>=n)
                return n;

        }
    }

    return mid;

}


int main(){
   ll n,m;cin>>n>>m;
    ll monk[n],notMonk[m];
    for(ll i=0;i<n;i++)
        cin>>monk[i];
    for(ll i=0;i<m;i++)
        cin>>notMonk[i];
        
    sort(monk,monk+n);
    sort(notMonk,notMonk+m);

    ll monkValue=0;
    ll notMonkValue=0;

    for(ll i=0;i<n;i++){
        ll a = strictGreater(notMonk,m,monk[i]);
        ll b = strictSmaller(notMonk,m,monk[i]);

        //cout<<a<<" "<<b<<endl;

        monkValue += (a*b);
    }

    for(ll i=0;i<m;i++){
        ll a = strictGreater(monk,n,notMonk[i]);
        ll b = strictSmaller(monk,n,notMonk[i]);

        //cout<<a<<" "<<b<<endl;

        notMonkValue += (a*b);
    }



    if(monkValue > notMonkValue)
        cout<<"Monk "<<(monkValue-notMonkValue)<<endl;
    else if(notMonkValue > monkValue)
        cout<<"!Monk "<<(notMonkValue-monkValue)<<endl;
    else
        cout<<"Tie"<<endl;



}

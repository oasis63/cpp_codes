#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long int 

ll nextMinCost(ll cost[],ll n,ll i,ll preMin){

    ll index=i;
    ll get = 0;

    for(index=i+1;index<n;index++){
        if(cost[index] <= preMin){
            get=1;
            break;
        }
    }

    if(get==0)
        return -1;

    return index;
}



ll solve(ll cost[],ll litre[],ll n){

    ll petrol = 0;
    ll price = 0;

    ll totalLitres[n]={0};
    totalLitres[0] = litre[0];

    for(ll i=1;i<n;i++){
        totalLitres[i]=totalLitres[i-1]+litre[i];
    }

    //prll(totalLitres,n);

    ll litres = 0;
    ll prev=0;

    for(ll i=0;i<n;i++){
       // cout<<i<<" :";
        ll index = nextMinCost(cost,n,i,cost[i]);
        //cout<<index<<endl;

        if(index==-1){   // last index 
            litres = totalLitres[n-1] - prev;
            //cout<<"Litres : "<<litres<<endl;
            prev = totalLitres[n-1];
            price += litres*cost[i];
           // cout<<"price : "<<price<<endl;
            break;
        }


        litres = totalLitres[index-1] - prev;
        prev=totalLitres[index-1];
        price += litres*cost[i];

        i=index-1;
    }
   // cout<<endl;
    return price;
}



int main(){

    ll tc;cin>>tc;
    while(tc--){
        ll n;cin>>n;
        ll cost[n];
        ll litre[n];

        for(ll i=0;i<n;i++)
            cin>>cost[i];
        for(ll i=0;i<n;i++)
            cin>>litre[i];

        cout<<solve(cost,litre,n)<<endl;

    }


}


/*
    Sample TestCase 

1
9
3 6 2 4 8 2 4 6 1
2 5 9 3 4 1 3 2 3

correct O/P is 68


1
2
5 1
1 2

correct O/P is 7

*/
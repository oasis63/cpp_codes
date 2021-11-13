/*
    Buy Maximum Stocks
*/

#include<bits/stdc++.h>
using namespace std;


int buyMaximumProducts(int n,int k,int price[]){

    vector<pair<int,int>>vect;

    int ans=0;

    for(int i=0;i<n;i++){
        vect.push_back(make_pair(price[i],i+1)); // price,maximum number of product which can be bought on that day
    }


    sort(vect.begin(),vect.end());

    for(int i=0;i<vect.size();i++){
        int item_count = min(vect[i].second,k/vect[i].first);
        ans += item_count;
        k-=vect[i].first*item_count;
    }



    return ans;
}





int main(){

    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;   // customer money

    cout << buyMaximumProducts(n, k, price) << endl;


    int price2[] = {7,10,4};
    n=sizeof(price2)/sizeof(price2[0]);
    k=100;

    cout<<buyMaximumProducts(n,k,price2)<<endl;

    return 0;
}

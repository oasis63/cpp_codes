#include<bits/stdc++.h>
using namespace std;

/*
Maximize the number of elments bought using the given amount of money 
*/

int solve(int money,vector<int> bq,vector<int> bp){

    int n = bq.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        cout<<bq[i]<<" ";
        cout<<bp[i]<<endl;
    }

    vector<double> ratio(n);

    for(int i=0;i<n;i++){
        ratio.push_back(bq[i]/(double)bp[i]);
    }

    sort(ratio.rbegin(),ratio.rend());  // decreasing order 


   
    for(int i=0;i<n;i++){
        if(money - bp[i] >= 0){
            int div = money/bp[i];
            money = money%bp[i];
            ans += bq[i]*div;
        }
    }

   
   // cout<<money<<endl;

    return ans;
}

int main(){
    
    int money = 50;
    vector<int> bq({20,1});
    vector<int> bp({12,2});

    int ans = solve(money,bq,bp);

    cout<<ans<<endl;
    

    return 0;
}
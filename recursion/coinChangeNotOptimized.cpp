#include<bits/stdc++.h>
using namespace std;

// denominations of coins

int countCoins(int total){

    if(total < 1 )
        return 0;

    int coins = 0;
    vector<int> vect{10,1};

    int len = vect.size();

    for(int i=0;i<len;i++){

        if(total >= vect[i]){
            coins += total/vect[i];
            total %= vect[i];
        }
        
        if(total == 0)
            break;
    }

    return coins;
}


int solveUtil(int denos[],int currIndex,int n,int sum){

    if(sum == 0)
        return 1;

    if(sum < 0)
        return 0;

    if(currIndex == (n-1) && sum < denos[currIndex] && sum!=0)
        return 0;
    

    int ans = 0;

    for(int i=currIndex;i<n;i++){
        if(denos[i] <= sum){
            ans += solveUtil(denos,i,n,sum-denos[i]);
        }
    }


    return ans;
}


void solve(int denos[],int n,int sum){

   /* int denos[] = {1,2,3};
    int n = 3;
    int sum = 4;*/

    sort(denos,denos+n);

    int cnt = solveUtil(denos,0,n,sum);

    cout<<cnt<<endl;
}



// recursion solution for coin change 
// Two possibilities for a given coin
//  1) Solution which contains the coin
//  2) Solution which does not contain the coin 

// count the number of solutions for the given sum 
int recurCoinChange(int denos[],int n,int sum){

    if(sum == 0)
        return 1;
    if(sum<0)
        return 0;
    if(sum>=1 && n<=0)
        return 0;

    // don't add in the  solution :+:  add in a solution
    return recurCoinChange(denos,n-1,sum) + recurCoinChange(denos,n,sum-denos[n-1]);
}




int main(){
    
    int tc,n,sum;
    cin>>tc;
    while(tc--){
        cin>>n;
        int deons[n];
        for(int i=0;i<n;i++)
            cin>>deons[i];
        cin>>sum;
        // sort(deons,deons+n);
        // solve(deons,n,sum);
        cout<<recurCoinChange(deons,n,sum)<<endl;
    }



    return 0;
}


/*

2
3
1 2 3
4
4
2 5 3 6
10


*/
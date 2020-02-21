#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MOD 1000000007ll

int findBitPairSum(vector<int> &arr) {
    
    int n = arr.size();

    int sum = 0;

    for(int i=0;i<32;i++){
        
        LL count = 0;

        for(int j=0;j<n;j++){
            //checking if the ith bit of arr[j] element is set 

            if(arr[j] & (1<<i))
                count++;
        }

        sum += (count*((LL)n-count)*2)%MOD;
        if(sum >= MOD)
            sum -= MOD;
            
    }

    return sum;
}

int main(){

    vector<int> vect {1,3,5};
    
    cout<<findBitPairSum(vect)<<endl;

    return 0;
}   
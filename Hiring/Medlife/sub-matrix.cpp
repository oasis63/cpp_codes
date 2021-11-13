#include<bits/stdc++.h>
using namespace std;

#define LEN 1000001

int primeNumbers[LEN];

int checkPrime(int n){

    if(n<=1)
        return 0;
    if(n==2)
        return 1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int min(int a,int b,int c){
    return min(a,min(b,c));
}

int solve (vector<vector<int> > arr) {
   // Write your code here
   int n = arr.size();
   int primes = 0;
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(checkPrime(arr[i][j]))
            primes++;
       }
   }

   int dp[n][n];

   for(int i=0;i<n;i++)
    dp[i][0] = checkPrime(arr[i][0]);

    for(int j=0;j<n;j++)
        dp[0][j] = checkPrime(arr[0][j]);

    int mx=0;

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(checkPrime(arr[i][j])){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1;
                if(dp[i][j] > mx)
                    mx = dp[i][j];
            }
            else
                dp[i][j]=0;
        }
    }

    int ans=primes;

    for(int i=1;i<mx;i++){
        ans += (mx-i)*(mx-i);
    }

    return ans;
}

void setPrimes(){

    for(int i=0;i<LEN;i++){
        primeNumbers[i]=1;
    }

    primeNumbers[0] = 0;
    primeNumbers[1] = 0;

    for(int i=2;i<LEN;i++){
        if(primeNumbers[i]){
            for(int j=2*i;j<LEN;j+=i){
                primeNumbers[j]=0;
            }
        }
    }


}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    setPrimes();


    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(n));
    for (int i_arr=0; i_arr<n; i_arr++)
    {
    	for(int j_arr=0; j_arr<n; j_arr++)
    	{
    		cin >> arr[i_arr][j_arr];
    	}
    }

    int out_;
    out_ = solve(arr);
    cout << out_;
}

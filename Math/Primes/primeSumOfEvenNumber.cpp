#include<bits/stdc++.h>
using namespace std;

vector<int> primesum(int n) {

    vector<bool> primes(n+1,true);

    primes[0]=false;
    primes[1]=false;

    for(int i=2;i<=n;i++){

    	if(!primes[i])
    		continue;
    	if( i > n/i)
    		break;

        for(int j=i*i;j<=n;j+=i){
            primes[j]=false;
        }
    }


    vector<int> ans;

    for(int i=2;i<=n; i++){
        if(primes[i] && primes[n-i]){
            ans.push_back(i);
            ans.push_back(n-i);
            break;
        }
    }

    return ans;
}

int main(){

    // int n = 16777214;    // 31   167777183
  	
  	int n = 12;   // 12  =  5 + 7

   	vector<int> ans = primesum(n);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	cout<<endl;

	return 0;
}

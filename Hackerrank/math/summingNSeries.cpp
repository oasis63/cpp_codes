#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

const ull mod = 1000000007;

int main(){

   int tc;
    cin>>tc;
    while(tc--){
        ull n;
        cin>>n;
        n =  ((n%mod)*(n%mod))%mod;
        cout<<n<<endl;
    }


}


/*
	#Sample input / output

	#Input

	10
	5773408242017850
	5025554062339313
	9803332417649065
	4529826640896246
	7633499047094366
	4614556128541569
	8200111660324493
	9428242699249167
	3888311265122983
	2400440231598721


	#Output
	
	112242846
	224225402
	27866312
	696985755
	210094750
	364229804
	770629628
	249617754
	321706764
	69640712



*/
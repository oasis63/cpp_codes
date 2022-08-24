#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

void printVector(vector<int> vect){
    int n = vect.size();
    for(int i=0;i<n;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}


void solve(){
    int n,k,num;
    cin>>n>>k;
    vector<int>vect;
    for(int i=0;i<n;i++){
        cin>>num;
        vect.push_back(num);
    }
    sort(vect.begin(),vect.end()); // increading order

    // vector<ll> aggregateVect;
    int lastValue=vect[0];
    int lastIndex = 0;
    ll aggregateValue=0;

	multiset<ll> ms;

    for(int i=1;i<n;i++){
        if(vect[i] != lastValue){
            aggregateValue = (lastValue*(i-lastIndex))*1ll;
			ms.insert(aggregateValue);

            lastIndex = i;
            lastValue = vect[i];
        }
    }   
    // for the lasIndexValue 
	aggregateValue = (lastValue*(n-lastIndex))*1ll;
    ms.insert(aggregateValue);

	ll sum = 0;
	int cnt = 0;
	while(ms.size() > 0 && cnt < k){
		ll elem = *ms.rbegin();
		if(elem <= 0)
			break;
		sum += elem;
		cnt++;
		ms.erase(ms.find(elem));
	}

	cout<<sum<<endl;

}

int main(){

    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }


    return 0;
}
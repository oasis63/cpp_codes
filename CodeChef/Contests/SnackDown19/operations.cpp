#include<bits/stdc++.h>
using namespace std;

#define ll long long

void print(ll arr[],ll n){
	for(ll i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
    
    std::ios_base::sync_with_stdio(false);

    int tc;
    cin>>tc;
    assert(tc>=1 && tc<= 1000);

    while(tc--){
        int n;cin>>n;
        assert(n>=1 && n<= 100000);
        ll a[n];
        ll b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            assert(a[i]>=0 && a[i]<=100000000);
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
            assert(b[i]>=0 && b[i]<=100000000);
        }

        bool flag = true;

        for(ll i=0;i<n-2;i++){
            if(a[i]==b[i]){
                continue;
            }else if(a[i] < b[i]){
            	int temp = b[i] - a[i];
                a[i]+=1*temp;
                a[i+1]+=2*temp;
                a[i+2]+=3*temp;
            }else if(a[i] > b[i]){
                flag=false;
                break;
            }
        }

        if(a[n-2] != b[n-2]  || a[n-1] != b[n-1]){
            flag=false;
        }

        //print(a,n);

        if(flag)
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }

    return 0;
}
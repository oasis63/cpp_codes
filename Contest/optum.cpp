#include <bits/stdc++.h>
using namespace std;

int solve(vector <int> ar){
	int n = ar.size();
	vector<int> h(n,0);

	int l = n;
	
	while(l > 1){
		l=0;
		int f = 1;
		for(int i=0;i<n;i++){
			if(h[i]==0){

				if(f==1){
					h[i]=1;
					f=0;
				}
				else{
					f=1;
					l++;
				}
			}
		}

		for(int i=0;i<n;i++) cout<<h[i]<<" "; cout<<"\n";
	}
	for(int i=0;i<n;i++) if(h[i]==0) return ar[i];
}
int main(){
	//{-5,9,7,3,-4,7}
	cout<< solve({-5,9,7,3,-4,7}) <<"\n";
	return 0;
}
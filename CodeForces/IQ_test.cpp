#include<bits/stdc++.h>
using namespace std;

bool even(int n){
	if(n%2==0)
		return true;
	return false;
}

int main(){
	
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int odd_count=0,even_count=0,same=0;

	for(int i=0;i<n;i++){
		if(even(arr[i])){
			even_count++;
		}else{
			odd_count++;
		}
	}

	if(even_count == 1){

		for(int i=0;i<n;i++){
			if(even(arr[i])){
				cout<<(i+1)<<endl;
				break;
			}
		}

	}else if(odd_count==1){

		for(int i=0;i<n;i++){
			if(!even(arr[i])){
				cout<<(i+1)<<endl;
				break;
			}
		}

	}else{

		int visit[101] = {0};

		// same 
		for(int i=0;i<n;i++){
			same = 0;
			visit[arr[i]]++;
			for(int j=i+1;j<n;j++){
				if(arr[j] == arr[i]){
					same++;
					visit[arr[j]]++;
				}
				if(same > 2){
					break;
				}
			}
			if(same==1 && visit[arr[i]] == 1){
				cout<<(i+1)<<endl;
				break;
			}
		}

	}





	return 0;
}
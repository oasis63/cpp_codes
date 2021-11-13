#include<bits/stdc++.h>
using namespace std;

int smallMissingNumber(int arr[],int n){

	unordered_map<int,int> mp;

	for(int i=0;i<n;i++){
		if(arr[i] > 0){
			mp[arr[i]]++;
		}
	}

	int num = 1;

	while(1){
		if(mp[num] == 0){
			return num;
		}
		num++;
	}
	return num;

}

int main(){
	
	int arr[] = {-5,2,0,-1,-10,15,1};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<smallMissingNumber(arr,n)<<endl;

	return 0;
}
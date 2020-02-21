#include<bits/stdc++.h>
using namespace std;

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<i<<" "<<arr[i]<<endl;
	}
	cout<<endl;
}

int main(){
	
	int arr[50];
	memset(arr,0,sizeof(arr));
	int n=50;


	print(arr,n);


	return 0;
}
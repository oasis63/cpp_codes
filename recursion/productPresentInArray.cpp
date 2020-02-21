#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,int n,int prod,int x){

    if(i>=n){
		return 0;
    }

	if(arr[i]*prod <x){
		// two cases .... 1) multiply the array value   and   2)  ignore it
        return solve(arr,i+1,n,prod,x)+solve(arr,i+1,n,prod*arr[i],x);
	}else if(prod*arr[i] == x){
		return 1;
	}
	else
		return 0;
}

int main(){

	//int arr[] = {4,5,6,3,8};
	int arr[] = {4,5,6,5,4};
	int n = 5;
	int prod = 1;
	int x = 20;

	cout<<solve(arr,0,n,prod,x)<<endl;
}

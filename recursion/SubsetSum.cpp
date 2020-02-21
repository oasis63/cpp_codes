#include<bits/stdc++.h>
using namespace std;


bool isSubsetSum(int arr[],int n,int sum){

	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(arr[n-1] > sum)
		return isSubsetSum(arr,n-1,sum);

	return  isSubsetSum(arr,n-1,sum) || isSubsetSum(arr,n-1,sum-arr[n-1]);
}


int main(){

	int arr[] = {3,34,4,12,5,2};
	int n = 6;
	int sum = 2;

	cout<<isSubsetSum(arr,n,sum)<<endl;
}
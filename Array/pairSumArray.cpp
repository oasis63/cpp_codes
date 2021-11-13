#include<bits/stdc++.h>
using namespace std;

void hasPairSum(int arr[],int n,int sum){

	bool found = false;

	int i=0;
	int j=n-1;

	while(i<j){
		
		int temp = arr[i]+arr[j];
		if(temp==sum){
			found=true;
			break;
		}

		if(temp > sum)
			j--;
		else if(temp < sum)
			i++;
	}

	if(found)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}

int main(){
	
	// input numbers ar sorted
	
	int arr[] = {1,2,3,9};
	int arr2[] = {1,2,4,4};
	int sum = 8;
	int n=4;


	hasPairSum(arr,n,sum);
	hasPairSum(arr2,n,sum);
	return 0;
}
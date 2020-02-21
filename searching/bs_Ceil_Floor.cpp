#include<bits/stdc++.h>
using namespace std;


// find the ceil and floor value for the given number
// the array is sorted , so we can use binary seach alogrithm
// since we need to find a number 


int floor(int arr[],int n,int num){

	int ans = -1;
	int start = 0,end = n-1,mid;

	while(start <= end){

		mid = start + (end - start)/2;

		if(arr[mid] == num){
			ans = arr[mid];
			break;
		}else if(arr[mid] < num){

			if((mid+1) >= n){
				ans = arr[mid];
				break;
			}

			if(arr[mid+1] > num){
				ans = arr[mid];
				break;
			}

			start = mid + 1;
		}else{
			end  = mid - 1;
		}

	}

	return ans;
}


int ceil(int arr[],int n,int num){

	int ans = -1;
	int start = 0,end = n-1,mid;

	while(start <= end){

		mid = start + (end - start)/2;

		if(arr[mid] == num){
			ans = arr[mid];
			break;
		}else if(arr[mid] < num){
			start = mid + 1;
		}else{

			if((mid-1) < 0){
				ans = arr[mid];
				break;
			}

			if(arr[mid-1] < num){
				ans = arr[mid];
				break;
			}

			end  = mid - 1;
		}

	}

	return ans;
}



int main(){
	
	// sorted array 	
	int arr[] = {1,4,6,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int num = 5;

	cout<<"floor : " << floor(arr,n,num)<<endl;
	cout<<"Ceil : "<< ceil(arr,n,num)<<endl;
}
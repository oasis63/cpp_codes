#include<bits/stdc++.h>
using namespace std;

void displayArr(int arr[],int n){	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int solve(int arr[],int n){

	int steps[n];
	for(int i=0;i<n;i++)
		steps[i] = -1;

	steps[0] = 0;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){

			if(arr[j] == 0)
				continue;

			if((arr[j] + j) >= i){ 

				if(steps[j] != -1 && steps[i] == -1)
					steps[i] = steps[j] + 1;
				else if(steps[j] != -1 && steps[i] != -1){
					steps[i] =  min(steps[i],steps[j] + 1);
				}
			}
		}
	}

	displayArr(steps,n);

	return steps[n-1];
}


int main(){
	//code
	
	
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   	
	   	cout<<solve(arr,n)<<endl; 
	}
	
	return 0;
}
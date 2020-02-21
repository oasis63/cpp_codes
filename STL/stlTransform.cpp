// Using tansform() in STL to add two arrays 
#include <bits/stdc++.h> 
using namespace std; 

int main() {

	int arr1[] = {1, 2, 3}; 
	int arr2[] = {4, 5, 6}; 
	int n = sizeof(arr1)/sizeof(arr1[0]); 
	int addition[n];  
	int substraction[n];  

	// Single line code to add arr1[] and arr2[] and 
	// store result in res[] 
	transform(arr1, arr1+n, arr2, addition, plus<int>()); 
	transform(arr1, arr1+n, arr2, substraction, minus<int>()); 

	for (int i=0; i<n; i++) 
		cout << addition[i] << " "; 

	cout<<endl;

	for(int i=0;i<n;i++)
		cout<<substraction[i]<<" ";
} 

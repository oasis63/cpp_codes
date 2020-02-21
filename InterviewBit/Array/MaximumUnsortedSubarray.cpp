#include<bits/stdc++.h>
using namespace std;

/*
Maximum Unsorted Subarray
*/

vector<int> subUnsort(vector<int> &A) {

	vector<int> ans;
    int n = A.size();
    int i=0,j=n-1;

   	while(i<n-1 and A[i] <= A[i+1]){
   		i++;
   	}
   	while(j>0 and A[j]>=A[j-1]){
   		j--;
   	}
    
    if(i==n-1){
    	ans.push_back(-1);
    	return ans;
    }

    int mn=A[i+1];
    int mx=A[i+1];

    for(int k=i;k<=j;k++){
    	mn=min(mn,A[k]);
    	mx=max(mx,A[k]);
    }

    int l=0,r=n-1;
    while(A[l] <= mn && l<=i){
    	l++;
    }
    while(A[r]>=mx && r>=i){
    	r--;
    }

    ans.push_back(l);
    ans.push_back(r);
    
    return ans;
}



int main(){
	
	// vector<int> vect { 4, 15, 4, 4, 15, 18, 20};   // 1 3
	// vector<int> vect{1,3,2,4,5};
	vector<int> vect{1, 2, 3, 5, 6, 13, 15, 16, 17, 13, 13, 15, 17, 17, 17, 17, 17, 19, 19};
	vector<int> ans = subUnsort(vect);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	/*cout<<endl;
	sort(vect.begin(),vect.end());
	for(int i=0;i<vect.size();i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;*/
	return 0;
}

/*

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that 
sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.



*/
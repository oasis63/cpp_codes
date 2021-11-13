#include<bits/stdc++.h>
using namespace std;

/*

Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

*/


vector<int> wave(vector<int> &A) {

	sort(A.begin(),A.end());

	vector<int> ans(A);

	int j = 0;

	for(int i=1;i<A.size();i+=2){
		ans[j] = A[i];
		j+=2;
	}

	j = 1;

	for(int i=0;i<A.size();i+=2){
		ans[j] = A[i];
		j+=2;
	}


	return ans;
}


int main(){
	
	vector<int> vect{1,3,2,4};

	vector<int> ans = wave(vect);

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	cout<<endl;

	return 0;
}
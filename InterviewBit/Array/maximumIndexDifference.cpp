#include<bits/stdc++.h>
using namespace std;

/*
	
	Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

	If there is no solution possible, return -1.

	Example :

	A : [3 5 4 2]

	Output : 2 
	for the pair (3, 4)

*/

int maximumGap(const vector<int> &arr) {

    
    int n = arr.size();

    if(n<=1)
    	return  0;
    
    vector<pair<int,int>> vect;
    for(int i=0;i<n;i++){
        vect.push_back(make_pair(arr[i],i));
    }
    
    sort(vect.begin(),vect.end());

    int len = vect.size();
    int ans = 0;
    int maxIndex = vect[len-1].second;

    for(int i=len-2;i>=0;i--){
        ans = max(ans,maxIndex-vect[i].second);
        maxIndex = max(maxIndex,vect[i].second);
    }

    return ans;
}


int main(){

	
	vector<int> vect{3,5,4,2};

	cout<<maximumGap(vect)<<endl;


	return 0;
}
#include<bits/stdc++.h>
using namespace std;

/*
similar to no. of platforms required for trains
*/

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {

	if(K==0)
		return false;

	vector<pair<int,int>> guest;

	int n = arrive.size();

	for(int i=0;i<n;i++){
		guest.push_back(make_pair(arrive[i],1));
		guest.push_back(make_pair(depart[i],0));
	}

	sort(guest.begin(),guest.end());   // sort by arrival time 

	int currActive = 0;
	int maxAns = 0;

	for(int i=0;i<guest.size();i++){

		if(guest[i].second == 1){  // arrival 
			currActive++;
			maxAns = max(maxAns,currActive);
		}else{					  // departure
			currActive--;
		}
	}

	if(K >= maxAns)
		return true;

	return false;
}



int main(){

	
	/*vector<int> arrival{30, 12, 15, 2, 21, 12, 1, 31, 7, 40, 29, 6, 48, 19, 23, 10, 26, 6, 20, 44, 44, 34, 44, 38};
	vector<int> depart{36, 54, 47, 19, 66, 33, 41, 69, 23, 80, 64, 28, 93, 23, 62, 15, 49, 19, 58, 64, 60, 60, 57, 82};
	int k = 23;*/

	vector<int> arrival{1,3,5};
	vector<int> depart{2,6,8};
	int k = 1;

	cout<<hotel(arrival,depart,k)<<endl;



	return 0;
}



/*

A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms. Bookings contain an arrival date and a departure date. 
He wants to find out whether there are enough 
rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room.


*/
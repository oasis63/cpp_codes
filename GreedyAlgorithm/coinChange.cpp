#include<bits/stdc++.h>
using namespace std;

// denominations of coins

int countCoins(int total){

	if(total < 1 )
		return 0;

	int coins = 0;
	vector<int> vect{10,1};

	int len = vect.size();

	for(int i=0;i<len;i++){

		if(total >= vect[i]){
			coins += total/vect[i];
			total %= vect[i];
		}

		if(total == 0)
			break;
	}

	return coins;
}

int main(){
	
	cout<<countCoins(31)<<endl;

	return 0;
}
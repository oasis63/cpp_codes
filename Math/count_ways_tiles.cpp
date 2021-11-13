#include<bits/stdc++.h>
using namespace std;

/*
	No. of ways to cover a tiles 2XN 
	with 2X1 tiles 
	
	-------
	|------
	|----


*/

int tile_ways(int n){
	if(n <= 2){
		return n;
	}
	return tile_ways(n-1)+tile_ways(n-2);
}

int main(){
	
	cout<<tile_ways(2)<<endl;
	cout<<tile_ways(3)<<endl;
	cout<<tile_ways(4)<<endl;

	return 0;
}
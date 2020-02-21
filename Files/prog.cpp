#include<bits/stdc++.h>
using namespace std;



int main(){

	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");


	int n;fin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
		fin>>arr[i];

	for(int i=0;i<n;i++){
		fout<<arr[i]<<" ";
	}
	

	fin.close();
	fout.close();
	return 0;
}
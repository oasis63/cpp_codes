// Given pairwise sum of n numbers, find the numbers

#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

void findNumbers(int arr[],int n){

  int num[n];

  int b_minus_a = arr[n-1]-arr[1];

  num[1] = (b_minus_a + arr[0])/2;
  num[0] = arr[0]-num[1];

  for(int i=1;i<=(n-2);i++){
    num[i+1] = arr[i] - num[0];
  }

  cout<<"\nNumbers are : "<<endl;
  for(int i=0;i<n;i++){
    cout<<num[i]<<" ";
  }

  cout<<endl;
}

int main(){
  
  int arr[] = {13, 10, 14, 9, 17, 21, 16, 18, 13, 17}; 
  int n = 5; // n is not size of array, but number of 
             // elements whose pairwise sum is stored 
             // in arr[] 
  findNumbers(arr, n); 

  return 0;
}
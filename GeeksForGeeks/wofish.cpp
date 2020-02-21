#include<bits/stdc++.h>
using namespace std;

int func(vector<int> arr[],int i,int j){


    if(i==0 && j==0)
        return arr[i][j];
    if((i+j)%2==0){
        return arr[i-1][j-1]+func(arr,i-1,j-1);
    }else{

        if(arr[i-1][j] > arr[i][j-1]){
            return arr[i-1][j] +  func(arr,i-1,j);
        }else{
            return arr[i][j-1] + func(arr,i,j-1);
        }
    }

}

int main(){

   int n;cin>>n;
   vector<int> arr[n];

   int temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            arr[i].push_back(temp);
        }
    }

    int sum = func(arr,n-1,n-1);

    cout<<sum<<endl;
}

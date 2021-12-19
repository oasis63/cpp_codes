#include<bits/stdc++.h>
#include<vector>
using namespace std;

int minDist(int N,int X[]){
    
    int result = -404;

    int sum = 0;    

    for(int i=0;i<N;i++){
        sum += X[i];
    }

    int avg = sum/N;

    cout<<avg<<endl;
    cout<<N<<endl;


    result = 0;

    for(int i=0;i<N;i++){
        result += abs(avg - X[i]);
    } 

    return result;
}


int main(){

   /*  int arr[] = {1,3,5};
    int n = 3;

    
    cout<<minDist(n,arr)<<endl;

    vector<int> vect; */    

    int n;
    cin>>n;


    cout<<n<<endl;



    return 0;
}
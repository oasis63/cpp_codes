#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 6;
    int arr[] = {4,5,4,5,3,1};

    int visited[1001];

    for(int i=0;i<=1000;i++){
        visited[i]=0;
    }


    int sum=0;

    for(int i=0;i<n;i++){
        int x= arr[i];
        for(int j=x;j<=1000;j++){
            if(!visited[j]){
                visited[j]=1;
                arr[i]=j;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        sum+=arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<sum<<endl;
}

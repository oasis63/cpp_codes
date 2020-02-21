#include<bits/stdc++.h>
using namespace std;

int checkTriagle(int a,int b,int c){

    int ans = 1;

    if((a+b) < c){
        ans = 0;
    }

    if((b+c) < a){
        ans = 0;
    }


    if((c+a) < b){
        ans = 0;
    }

    return ans;
}

int minPerimeter(int arr[],int n){

    int peri = INT_MAX;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){

                if(checkTriagle(arr[i],arr[j],arr[k])){
                    int temp = arr[i] + arr[j] + arr[k];
                    if(temp < peri)
                        peri = temp;
                }

            }
        }
    }

    return peri;
}

int main(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    int result = minPerimeter(arr,n);

    if(result == INT_MAX){
        cout<<"-1"<<endl;
    }else{
        cout<<result<<endl;
    }

}

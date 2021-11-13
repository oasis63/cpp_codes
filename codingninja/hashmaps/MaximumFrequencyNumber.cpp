#include<bits/stdc++.h>
using namespace std;

int highestFrequency(int *input, int n){     
    
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        int key = input[i];
        if(m.count(key) == 0){
            m[key]=1;
        }else{
            m[key]++;
        }
    }
    
    int ans = input[0];
    int max_count = m[input[0]];

    for(int i=0;i<n;i++){
        if(m[input[i]] > max_count){
            ans = input[i];
            max_count = m[input[i]];
        }
    }

    return ans;
}

int main(){


    int arr []= {4 ,12 ,2 ,11 ,12 ,2 ,1, 2,2,11 ,12 ,2 ,6 };
    int n = 13;
    // int n;
    // cin>>n;

    // int arr[n];
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];

    cout<<highestFrequency(arr,n)<<endl;
}


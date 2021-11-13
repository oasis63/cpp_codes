#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    int input[n];
    int ans[n];
    int ret = 0;
    int temp = 0;

    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    ans[0] = 1;

    for(int i=1;i<n;i++){
        if(input[i] > input[i-1]){
            ans[i]=ans[i-1]+1;
        }else{
            ans[i]=1;
        }
    }

    ret = ans[n-1];

    for(int i=n-2;i>=0;i--){
        if(input[i] > input[i+1]){
            temp = ans[i+1] + 1;
        }else{
            temp  = 1;
        }
        ret += max(temp,ans[i]);
        ans[i] = temp;
    }


    cout<<ret<<endl;

    return 0;
}

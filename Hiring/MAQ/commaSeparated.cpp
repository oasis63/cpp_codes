#include <bits/stdc++.h>
using namespace std;


int main(){

    string str;
    cin>>str;


    int len = str.length();
    int n = len/2 + 1;
    int arr[n];

    int j=0;
    for(int i=0;i<len;i++){
        if(str[i]!=','){
            arr[j] = (int)(str[i]-'0');
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }


}

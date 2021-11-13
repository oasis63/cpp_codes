#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    string text = "abcbcglx";
    string pattern = "bcgl";
    
    int n = text.length();
    int m = pattern.length();

    bool flag = true;

    for(int i=0;i<n;i++){
        int j = i;
        int k = 0;

        while(text[j] == pattern[k]  && j<n && k<m){
            j++;
            k++;
        }

        if(k==m){
            cout<<"found at "<<i<<endl;
            flag = false;
            break;
        }
    }

    if(flag)
        cout<<"Not found"<<endl;

    return 0;
}
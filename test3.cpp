#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int findInRange(string str,int l,int r,char b){
    int cnt=0;
    for(int i=l;i<=r;i++){
        char d = str[i];
        if(d==b)
            cnt++;
    }
    return cnt;
}

int main(){
    
    int n;cin>>n;
    string str; cin>>str;
    int cnt=0;
    int hash[26]={0};
    for(int i=0;i<n;i++){
        hash[str[i]-'a']++;
    }

    for(int i=0;i<n;i++){
        char a = str[i];
        if(hash[a-'a']>1){
            for(int j=i+1;j<n-1;j++){
                char c = str[j];
                if(c==a){
                    for(int k=j-1;k>i;k--){
                        char b = str[k];
                        cnt += findInRange(str,j+1,n-1,b);
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
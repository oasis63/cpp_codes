#include<bits/stdc++.h>
using namespace std;


int solve(string str,int k){

    int steps=0;
    int len = str.length();

    for(int i=0;i<len;i++){
        if(str[i]=='0'){
            //cout<<steps<<" " << str <<" "<<(i+k)<<" "<<i<<" ";

            if((i+k) > len){
                return -1;
            }

            int temp = k;
            int j = i;
            int mj = INT_MAX;

            while(temp){

                if(str[j]=='0'){
                    str[j] = '1';
                }else{
                    str[j]='0';
                    if(j < mj)
                        mj=j;
                }
                j++;
                temp--;
            }

            if(mj == INT_MAX){
                i=j-1;
            }else{
                i=mj-1;
            }

            steps++;
            //cout<<str<<endl;
        }
    }

    return steps;
}


int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        int k;
        cin>>str;
        cin>>k;
        cout<<solve(str,k)<<endl;
    }
}

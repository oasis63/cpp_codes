#include<bits/stdc++.h>
using namespace std;

// remove adjacent duplicates

int main(){

    string str = "acaaabbbacdddd";
    string ans = "";

    int len = str.length();

    // O(n^2)

    for(int i=0;i<len;i++){
        int count=0;
        for(int j=i+1;j<len;j++){
            if(str[i]==str[j]){
                count++;
            }else{
                break;
            }
        }

        if(count==0){
            ans += str[i];
        }else{
            i+=count;
        }
    }

    cout<<ans<<endl;
}

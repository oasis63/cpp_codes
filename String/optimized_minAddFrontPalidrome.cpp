#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

bool isPalindrome(string str){

    int n = str.length();

    int i=0,j=n-1;

    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}


int minimumAddFront(string str){

    int n = str.length();
    int ans = 0;

    bool flag = false;

    while(str.length() > 0){

        if(isPalindrome(str)){
            flag = true;
            break;
        }else{  
            ans++;
            str = str.substr(0,str.length()-1);
        }
    }

    if(flag)
        return ans;

    return -1;

}

int main(){
    
    string str = "aaaaa";

    cout<<minimumAddFront(str)<<endl;

    string st2 = "babb";

    cout<<minimumAddFront(st2)<<endl;



    return 0;
}
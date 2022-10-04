#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(string s){
        string rev = s;
        reverse(rev.begin(),rev.end());
        if(rev==s)
            return true;
        else
            return false;
    }

public:
    bool isPalindrome(string s) {
        cout<<"input string s : "<<s<<endl;
        int len = s.length();
        if( len == 0 || len == 1 ) return true;
        // remove spaces 

        transform(s.begin(),s.end(),s.begin(),::tolower);

        regex r(" ");

        cout<<regex_replace(s,r,"")<<endl;
        

        return check(s);
    }
};

int main(){
    Solution s;

    string str = "wow";
    while(true){
        cout<<s.isPalindrome(str)<<endl;
        // cin>>str;
        getline(cin, str);
    }

    return 0;
}
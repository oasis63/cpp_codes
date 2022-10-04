#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

class Solution {
private:
    bool isAllCharSame(vector<string>& strs,int index,int n){
        char c = strs[0][index];
        cout<<"char : "<< c<<endl;
        for(int i=0;i<n;i++){
            if(strs[i][index] !=c ){
                return false;
            }
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int smallest = INT_MAX;
        int n = strs.size();
        if(n==0) return "";
        for(int i=0;i<n;i++){
            int s = strs[i].length();
            if(s < smallest ) smallest = s;
        }
        cout<<smallest<<endl;
        string ans = "";
        for(int i=0;i<smallest;i++){
            if(isAllCharSame(strs,i,n)){
                ans += strs[0][i];
            }else break;
        }
        return ans;
    }
};

int main(){

    Solution s; 
    vector<string> strs{"flower","flow","flight"};
    
    for(int i=0;i<strs.size();i++){
        cout<<strs[i]<<endl;
    }
    cout<<s.longestCommonPrefix(strs)<<endl;


    return 0;
}
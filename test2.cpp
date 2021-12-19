#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

class Solution{
    public:
        string solve(string A);
};

bool largestPossible(string s,int len){
    int i = 1;
    while(i<len){
        if(s[i] != s[0])
            return true;
        i++;
    }
    return false;
}

string Solution::solve(string A) {
    int len = A.length();
    if(len == 1 || !largestPossible(A,len))
        return "-1";
    char second = A[1];
    int max_ = 1;
    bool found = false;
    for(int i=2;i<len;i++){
        if (!found && A[i] > max_){
            max_ = i;
            found = true;
        }else if(found && A[i] > second && A[i] < A[max_]){
            max_ = i;
        }
    }
    swap(A[1],A[max_]);
    string sub1 = A.substr(0,2);
    string sub2 = A.substr(2);
    sort(sub2.begin(),sub2.end());
    if(found)
        return sub1+sub2;
    else 
        return "-1";
}

int main(){

    Solution s;

    // cout<<s.solve("99fadsfsd999")<<endl;
    // cout<<s.solve("99")<<endl;

    // cout<<s.solve("9892")<<endl;
    cout<<s.solve("218765")<<endl;


    return 0;
}
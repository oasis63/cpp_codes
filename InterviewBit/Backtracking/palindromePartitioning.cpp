#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int s, int e) {

    while (s < e) {
        if (str[s] != str[e])
                return false;
        s++;
        e--;
    }

    return true;
}

void partitionUtil(string &str,int index,vector<string> &current,vector<vector<string>> &ans){

	 if(index ==  str.length()){
        ans.push_back(current);
        return;
    }

    for(int i=index;i<str.length();i++){

        if(isPalindrome(str,index,i)){
            current.push_back(str.substr(index,i-index+1));
            partitionUtil(str,i+1,current,ans);
            current.pop_back();
        }
    }

}

vector<vector<string> > partition(string str) {

    vector<vector<string>> ans;
    vector<string> current;

    partitionUtil(str,0,current,ans);

    sort(ans.begin(),ans.end());


    return ans;
}

int main(){

//    string str = "aab";

    string str = "abcbd";

    vector<vector<string>> ans = partition(str);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]



*/

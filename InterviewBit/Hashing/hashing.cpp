#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams(const vector<string> &A) {

    int n = A.size();
    vector<vector<int>> ans;
    map<string,vector<int>> mp;

    for(int i=0;i<n;i++){
        string tempStr = A[i];
        sort(tempStr.begin(),tempStr.end());
        mp[tempStr].push_back(i+1);
    }

    for(auto it = mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }


    return ans;
}


int main(){

    vector<string> vect{"cat","dog","god","tca"};
    vector<vector<int>> ans = anagrams(vect);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
Given an array of strings, return all groups of strings that are anagrams.
Represent a group by a list of integers representing the index in the original list

Input : cat dog god tca
Output : [[1, 4], [2, 3]]

*/

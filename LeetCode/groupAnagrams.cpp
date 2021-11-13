#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

 vector<vector<string>> groupAnagrams(vector<string>& vect) {
      
    map<string,vector<string>> mp;
    int n = vect.size();

    for(int i=0;i<n;i++){
        string str = vect[i];
        sort(str.begin(),str.end());
        mp[str].push_back(vect[i]);
    }

    vector<vector<string>> ret;

    for(auto it = mp.begin();it!=mp.end();it++){
        vector<string> tp = it->second;
        ret.push_back(tp);
    }


    return ret;
}

int main(){
   
    vector<string> vect{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = groupAnagrams(vect);

    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++)
            cout<<ret[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
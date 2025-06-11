#include <bits/stdc++.h>
using namespace std;



vector<string> ans;
int n ;

void helper(int j, string s, vector<string> &v){
    // cout<<"j :  " << j << endl;
    if( j == n){
        if( s.size() == n ) ans.push_back(s);
        return;
    }
    
    for(int i = 0; i< v[j].size();i++){
        char c = v[j][i];
        s.push_back(c);     
        helper(j+1, s, v);
        s.pop_back();
    }
}


vector<string> specialStrings(vector<string> &A) {
    vector<string> vect;
    n = int(A.size());
    helper(0,"",A);
    sort(ans.begin(), ans.end());
    return ans;
}



int main(){

    // vector<string> A = {"ab", "cd"};

    vector<string> A = {"yhf", "k" };


    vector<string> ans = specialStrings(A);

    cout<<endl;
    for(auto t : ans){
        cout<<t<<endl;
    }

    return 0;
}
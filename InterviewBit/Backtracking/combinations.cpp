#include<bits/stdc++.h>
using namespace std;

void combineHelper(vector<int> &current, int n, int k, vector<vector<int> > &ans) {

    if (k == 0) {
        vector<int> newEntry = current;
        reverse(newEntry.begin(), newEntry.end());
        ans.push_back(newEntry);
        return;
    }
    if (n == 0 || n < k) return;
    // We have 2 options here. We can either include n or not.
    // Option 1 : Do not include n.
    combineHelper(current, n - 1, k, ans);
    // Option 2 : Include n.
    current.push_back(n);
    combineHelper(current, n - 1, k - 1, ans);
    current.pop_back();

    return;

}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> current;
    combineHelper(current, n, k, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    vector<vector<int>> ans = combine(4,2);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

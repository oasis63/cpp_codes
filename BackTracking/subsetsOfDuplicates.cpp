#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
    if (index >= S.size()) {
        result.push_back(current);
        return;
    }
    // Ignore the current index.
    generateSubsets(S, index + 1, current, result);

    // Include the current index.
    current.push_back(S[index]);
    generateSubsets(S, index + 1, current, result);
    current.pop_back();
}

vector<vector<int> > subsetsWithDuplicates(vector<int> &S) {
    vector<vector<int> > ans;
    vector<int> current;
    sort(S.begin(), S.end());
    generateSubsets(S, 0, current, ans);
    sort(ans.begin(), ans.end());
     vector<vector<int>> ret;

    for(int i=0;i<ans.size();i++){     // removing the duplicate sets in the set
        if(i==0 || ans[i] != ans[i-1]){
            ret.push_back(ans[i]);
        }
    }

    return ret;
}




int main(){

    vector<int> input{1,2,2};

    vector<vector<int>> ans = subsetsWithDuplicates(input);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}

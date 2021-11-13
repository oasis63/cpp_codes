#include<bits/stdc++.h>
using namespace std;

vector<int> equal(vector<int> &vect) {

    vector<int> ans;
    unordered_map<int,vector<int> > sumInd;

    int n = vect.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = vect[i] + vect[j];

            if(find(sumInd[sum].begin(),sumInd[sum].end(),i) != sumInd[sum].end()){
                continue;
            }

            if(find(sumInd[sum].begin(),sumInd[sum].end(),j) != sumInd[sum].end()){
                continue;
            }

            sumInd[sum].push_back(i);
            sumInd[sum].push_back(j);
        }
    }

    for(auto it = sumInd.begin();it!=sumInd.end();it++){
        cout<<it->first<<"\n\t";
        vector<int> v = it->second;
        if(v.size() >= 4){
            vector<int> cpy(v.begin(),v.begin()+4);
            if(ans.size() == 0)
                ans = cpy;
            else if( cpy < ans){
                ans = cpy;
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return ans;
}

int main(){

    vector<int> vect {1, 1, 1, 1, 1};

    vector<int> ans = equal(vect);

    cout<<"\n-----"<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

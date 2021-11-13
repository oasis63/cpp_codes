#include<bits/stdc++.h>
using namespace std;

void display(vector<int> vect){

    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

void permutations(vector<int> &vect,int l,int r,vector<vector<int>> &ans){
	if(l==r){
//		display(vect);
        ans.push_back(vect);
	}else{
		for(int i=l;i<=r;i++){
			swap(vect[l],vect[i]);
			permutations(vect,l+1,r,ans);
			swap(vect[l],vect[i]);  // backtrack
		}
	}
}

vector<vector<int>> permute(vector<int> &vect) {

    vector<vector<int>> ans;
    int n = vect.size();
    permutations(vect,0,n-1,ans);

    return ans;
}

int main(){

   /* vector<int> vect { 1,2,3};
    permute(vect,0,vect.size()-1);*/

    vector<int> vect { 1,2,3};
    vector<vector<int>> ans = permute(vect);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

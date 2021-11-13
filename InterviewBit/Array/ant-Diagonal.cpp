#include<bits/stdc++.h>
using namespace std;

/*
input:

1 2 3
4 5 6 
7 8 9

//
Outpu:

1
2 4
3 5 7
6 8
9


*/

vector<vector<int>> diagonal(vector<vector<int> > &A) {

    vector<vector<int>> ans;
    int n = A.size();
    
    for(int j=0;j<n;j++){
        int t =j;
        int i=0;

        vector<int> temp;
        while(i<n && t>=0){
            temp.push_back(A[i][t]);
            i++;
            t--;
        }
        ans.push_back(temp);
        temp.clear();
    }

    for(int i=1;i<n;i++){

        int t =i;
        int j=n-1;

        vector<int> temp;
        while(i>0 && t<n){
            temp.push_back(A[t][j]);
            t++;
            j--;
        }
        ans.push_back(temp);
        temp.clear();

    }

    return ans;
}


int main(){
    
    vector<vector<int>> vect{{1,2,3,1},{4,5,6,1},{7,8,9,1},{10,11,12,1}};

    vector<vector<int>> ans = diagonal(vect);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
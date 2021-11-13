#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> prettyPrint(int A) {

    int n = 2*A-1;

    vector<vector<int>> vect(n);

    int val = A;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vect[i].push_back(0);
        }
    }


    for(int i=0;i<n;i++){

        // top and right of the matrix
        for(int j=i;j<n-i;j++){
            vect[i][j]=A;
            vect[j][i]=A;
            vect[n-i-1][n-j-1]=A;
            vect[n-j-1][n-i-1]=A;
        }

       A--;
    }

    return vect;
}


int main(){

    int n = 4;

    vector<vector<int>> ans =  prettyPrint(n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}


/*

# 4

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4


# 3

3 3 3 3 3
3 2 2 2 3
3 2 1 2 3
3 2 2 2 3
3 3 3 3 3

*/

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &vect,int val){

    int low = 0,high=vect.size()-1,mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(vect[mid] == val)
            return true;
        else if(val > vect[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int searchMatrix(vector<vector<int> > &mat, int val) {
    int n = mat.size();

    for(int i=0;i<n;i++){

        int m = mat[i].size();

        if(mat[i][0]==val || mat[i][m-1] == val)
            return 1;

        if(mat[i][0] < val && mat[i][m-1] > val){
            if(binarySearch(mat[i],val))
                return 1;
        }
    }

    return 0;
}




int main(){

    vector<vector<int>> vect =  {
                          {1,   3,  5,  7},
                          {10, 11, 16, 20},
                          {23, 30, 34, 50}
                            };

    cout<<searchMatrix(vect,553)<<endl;

    return 0;
}

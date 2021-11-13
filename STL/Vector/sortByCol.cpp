// sorting on the basis of a column 
#include<bits/stdc++.h>
using namespace std;

bool sortCol(const vector<int> &v1,const vector<int> &v2){
    return v1[1] < v2[1];
}

int main(){

    vector<vector<int>> vect{{3,5,1},
                             {4,8,6},
                             {7,2,9}};

    int rows = vect.size();

    int cols = vect[0].size(); // considering all vectors have same size

    cout<<"Matrix Before Sorting"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    // sorting on the basis of second column
    sort(vect.begin(),vect.end(),sortCol);

    cout<<"Matrix After Sorting"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

}
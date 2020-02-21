// sorting on the basis of size of vectors
#include<bits/stdc++.h>
using namespace std;

bool sortCol(const vector<int> &v1,const vector<int> &v2){
    return v1.size() < v2.size();
}


int main(){

    vector<vector<int>> vect{{1,2},
                             {4,8,6},
                             {3}};

    int rows = vect.size();

    cout<<"Matrix Before Sorting"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    // sorting on the basis of second column
    sort(vect.begin(),vect.end(),sortCol);
    

    cout<<"Matrix After Sorting"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

}
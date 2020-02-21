#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

//Maximum path sum in a triangle.

int findMaxSumPath(int triangle[][C],int i,int j){
    if(i>=R || j>=C)
        return 0;
    return triangle[i][j] + max(findMaxSumPath(triangle,i+1,j),findMaxSumPath(triangle,i+1,j+1));
}



int main(){

    int triangle[][C] = {
                            {3,0,0,0},{7,4,0,0},
                            {2,4,6,0},{8,5,9,3}
                        };
    int mxSum = findMaxSumPath(triangle,0,0);
    cout<<mxSum<<endl;


    int triangle2[][C] = {
                            {8,0,0,0},{-4,4,0,0},
                            {2,2,6,0},{1,1,1,1}
                        };
    mxSum = findMaxSumPath(triangle2,0,0);
    cout<<mxSum<<endl;
}

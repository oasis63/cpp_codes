#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

//Maximum path sum in a triangle.

int findMinSumPath(int triangle[][C],int i,int j){
    if(i>=R || j>=C)
        return 0;
    return triangle[i][j] + min(findMinSumPath(triangle,i+1,j),findMinSumPath(triangle,i+1,j+1));
}

//  dynamic solution for the above recursion solution
int minPathSum(int tri[][C], int m, int n)
{
     // loop for bottom-up calculation
     for (int i=m-1; i>=0; i--)
     {
        for (int j=0; j<=i; j++)
        {

            tri[i][j] += min(tri[i+1][j],tri[i+1][j+1]);

        }
     }


     return tri[0][0];
}

int main(){

    int triangle[][C] = {
                            {3,0,0,0},{6,4,0,0},
                            {5,2,7,0},{9,1,8,6}
                        };


    int mnSum = minPathSum(triangle,R-1,C-1);
    cout<<mnSum<<endl;


    int triangle2[][C] = {
                            {8,0,0,0},{-4,4,0,0},
                            {2,2,6,0},{1,1,1,1}
                        };

    mnSum = minPathSum(triangle2,R-1,C-1);
    cout<<mnSum<<endl;

    return 0;
}

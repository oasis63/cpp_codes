#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
        // Direction of move

            *---------
            |
            |
            |
            |

    */


    cout<<"Find the maximum sums of numbers from (0,0) to (r-1,c-1) \n"<<endl;


//     int grid[][2] = { {2,7},
//                        {5,3},
//                        {8,7},
//                    };

     int grid[][4] = { {0,2,5,1},
                    {5,7,3,6},
                    {9,1,7,8},
                    {6,10,11,5}
                };


    int r = 4;
    int c = 4;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    // first fill the first column

    for(int i=1;i<c;i++){
       grid[0][i]=grid[0][i-1] + grid[0][i];
    }

    cout<<endl;
    for(int i=0;i<c;i++){
        cout<<grid[0][i]<<" ";
    }


    // next fill the first column
    for(int i=1;i<r;i++){
      grid[i][0] = grid[i-1][0]+grid[i][0];
    }

    cout<<"\n\n";
    for(int i=0;i<r;i++){
        cout<<grid[i][0]<<endl;
    }

    // finding the maximum sum till the final point

    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(grid[i][j-1] > grid[i-1][j])
                grid[i][j] += grid[i][j-1];
            else
                grid[i][j] += grid[i-1][j];
        }
    }



    cout<<"\n\n....---Final Maximum Value  grid.....----\n"<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j]<<"  ";
        }
        cout<<endl;
    }


    cout<<"\nSo the answer is "<<grid[r-1][c-1] <<endl;

    cout<<endl;
    return 0;
}

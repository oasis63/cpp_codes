#include<bits/stdc++.h>
using namespace std;

int main(){



    int mat[][4] = { {10,20,30,40},
                     {15,25,35,45},
                     {27,29,37,48},
                     {32,33,39,50}
                    };
    int n = 4;

    // search this number in the given matrix in linear time
    int x = 29;

//    int x = 343;

    // start from the top right corner


    bool found = false;
    int i=0;
    int j=n-1;

    // linear time solution

    while((i>=0 && i<n) && (j>=0 && j<n)){

        if(mat[i][j]==x){
            found=true;
            cout<<"Element is present at : ";
            cout<<i<<" "<<j<<endl;
            break;
        }else if(mat[i][j] > x){
            j--;
        }else if(mat[i][j] < x){
            i++;
        }
    }

    if(!found)
        cout<<"Element is not present"<<endl;


}

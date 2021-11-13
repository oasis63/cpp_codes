/*
Paper Cut into Minimum Number of Squares
*/

#include<bits/stdc++.h>
using namespace std;


int countSquares(int small,int large){

    if(small==0 || large == 0)
        return 0;

    int count = large/small;
    large = large%small;

    if(small > large){
        swap(small,large);
    }

    return count+countSquares(small,large);
}

int main(){

    int l=13;
    int b = 29;

    int sm = min(l,b);
    int large = max(l,b);

    int countOfSquares = countSquares(sm,large);

    cout<<countOfSquares<<endl;


    l=4;
    b = 5;

    sm = min(l,b);
    large = max(l,b);

    countOfSquares = countSquares(sm,large);

    cout<<countOfSquares<<endl;
}

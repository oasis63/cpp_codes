#include<bits/stdc++.h>
using namespace std;


int coverPoints(vector<int> &x, vector<int> &y) {
    
    int n = x.size();
      if(n<=1)
        return 0;
    int ans = 0;
    for(int i=1;i<n;i++){
        ans += max(abs(x[i]-x[i-1]),abs(y[i]-y[i-1]));
    }
    return ans;
}


int main(){

    vector<int> x {0,1,1};
    vector<int> y {0,1,2};

    cout<<coverPoints(x,y)<<endl;
}


/*
    You are in an infinite 2D grid where you can move in any of the 8 directions :

    (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 

You are given a sequence of points and the order in which you need to cover the points. 
Give the minimum number of steps in which you can achieve it. You start from the first point.


Exmaple: 

    (0,0),(1,1),(1,2)

    ans:  2 
*/
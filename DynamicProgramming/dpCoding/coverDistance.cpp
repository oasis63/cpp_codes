//Count number of ways to cover a distance
//Given a distance ‘dist, count total number
//of ways to cover the distance with 1, 2 and 3 steps.
#include<bits/stdc++.h>
using namespace std;

// recursive solution
int countWays(int dist){
    if(dist < 0)
        return 0;
    if(dist==0)
        return 1;
    return countWays(dist-1)+countWays(dist-2)+countWays(dist-3);
}

// dynamic solution

int countWaysDyn(int dist){

    int counter[dist+1];
    counter[0]=1;
    counter[1]=1;
    counter[2] = 2;

    for(int i=3;i<=dist;i++){
        counter[i]=counter[i-1]+counter[i-2]+counter[i-3];
    }

    return counter[dist];
}

int main(){

    int dist = 3;
    cout<<countWays(dist)<<" "<<countWaysDyn(dist)<<endl;

    dist=4;
    cout<<countWays(dist)<<" "<<countWaysDyn(dist)<<endl;

    return 0;
}

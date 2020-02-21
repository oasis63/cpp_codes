#include<bits/stdc++.h>
using namespace std;

/*
Volume of all cubes equals the volume of the cuboid
*/

void maximizeCube(int l,int b,int h){

    int side = __gcd(l,__gcd(b,h));  // side of the cube

    int num = l/side;
    num=(num * b/side);
    num = (num*h/side);     // number of cubes formed from the cuboid

    cout<<side<<" "<<num<<endl;
}

int main(){

    int l=2,b=4,h=6;  // parameters of cuboid

    maximizeCube(l,b,h);
}

#include<bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
};

int main(){
	
	
  struct Point points[6] = {{0,0},{0,2},{2,0},{2,2},{4,0},{4,2}};

  for(Point p : points){
    cout<<p.x<<" "<<p.y<<endl;
  }

	return 0;
}
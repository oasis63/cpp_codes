#include<bits/stdc++.h>
using namespace std;

struct Point{
  int x,y;  
};


int countRectangles(){

  //  (x,y) , (x,y2)  , (x2,y) , (x2,y2)
  //  x != x2 && y != y2

  struct Point points[6] = {{0,0},{0,5},{2,0},{2,3},{4,0},{4,2}};

  map<pair<int,int>,int> count;

  int ans = 0;

  for(Point p : points){
    for(Point p_above : points){
      if(p.x == p_above.x && p.y < p_above.y){
        pair<int,int> pair_y{p.y,p_above.y};
        ans += count[pair_y];
        count[pair_y]++;
      }
    }
  }

  return ans;

}


int main(){
  
  cout<<countRectangles()<<endl;

  return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

float rounder(float var){
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}


int main(){
  
  int tc;cin>>tc;
  while(tc--){
    float a,b,c,d,e,t;
    float record = 9.58;
    cin>>a>>b>>c>>d;
    e = a * b * c * d;
    t = 100.0/e;
    t = rounder(t);
    if(t<record)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
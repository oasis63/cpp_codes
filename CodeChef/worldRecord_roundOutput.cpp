#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

float rounder(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    cout<<"value : "<<value<<endl;
    return (float)value / 100;
}


int main(){
  
  int tc;cin>>tc;
  while(tc--){
    float a,b,c,d,e,t;
    float record = 9.58;
    cin>>a>>b>>c>>d;
    e = a * b * c * d;
    cout<<e<<"  ";
    t = 100.0/e;
    cout<<t<<"  ";
    cout<<rounder(t)<<"  ";
    t = rounder(t);
    if(t<record)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}

/*

Sample Input:

3
1.0 1.0 1.0 10.45
1.0 1.0 1.0 10.44
1.0 1.0 0.9 10.44


Sample Output:
YES
NO
NO




*/
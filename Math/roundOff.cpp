#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

float roundOf(float var){
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

int main(){
	float f = 37.67933;

	float roundedValue = roundOf(f);

	cout<<roundedValue<<endl;

	return 0;
}
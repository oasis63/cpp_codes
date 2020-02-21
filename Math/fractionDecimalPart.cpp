#include<bits/stdc++.h>
using namespace std;


int main (){

  double param, fractpart, intpart;

  param = 3.14159265;

  fractpart = modf (param , &intpart);

  printf ("%f = %f + %f \n", param, intpart, fractpart);
  
  return 0;
}
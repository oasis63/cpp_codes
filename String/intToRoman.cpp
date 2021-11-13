#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

string intToRoman(int n) {
    
  int thousand,hundreds,tens,ones;
  string str = "";
 
  thousand=(n/1000);
  hundreds=(n/100)%10;
  tens=(n/10)%10;
  ones=(n/1)%10;

  if(thousand==1)
   str+="M";
  else if(thousand==2)
  str+="MM";
  else if(thousand==3)
  str+="MMM";

  if(hundreds==1)
  str+="C";
  else if(hundreds==2)
   str+="CC";
  else if(hundreds==3)
   str+="CCC";
  else if(hundreds==4)
   str+="CD";
  else if(hundreds==5)
  str+="D";
  else if(hundreds==6)
   str+="DC";
  else if(hundreds==7)
   str+="DCC";
  else if(hundreds==8)
    str+="DCCC";
  else if(hundreds==9)
   str+="CM";

  if(tens==1)
  str+="X";
  else if(tens==2)
   str+="XX";
  else if(tens==3)
   str+="XXX";
  else if(tens==4)
   str+="XL";
  else if(tens==5)
  str+="L";
  else if(tens==6)
   str+="LX";
  else if(tens==7)
   str+="LXX";
  else if(tens==8)
    str+="LXXX";
  else if(tens==9)
   str+="XC";

   if(ones==1)
   str+="I";
  else if(ones==2)
   str+="II";
  else if(ones==3)
   str+="III";
  else if(ones==4)
   str+="IV";
  else if(ones==5)
  str+="V";
  else if(ones==6)
   str+="VI";
  else if(ones==7)
   str+="VII";
  else if(ones==8)
    str+="VIII";
  else if(ones==9)
   str+="IX";


 return str;
}


int main(){
  
  
  cout<<intToRoman(1994)<<endl;  

  return 0;
}
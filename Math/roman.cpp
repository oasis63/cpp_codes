//Natural number to Roman Number
#include<iostream>
using namespace std;

int main()
{
  int n,thousand,hundreds,tens,ones;
  cout<<"Enter any natural number(1-3000)\n";
  cin>>n;
 
  thousand=(n/1000);
  hundreds=(n/100)%10;
  tens=(n/10)%10;
  ones=(n/1)%10;

  if(thousand==1)
   cout<<"M";
  else if(thousand==2)
  cout<<"MM";
  else if(thousand==3)
  cout<<"MMM";

  if(hundreds==1)
  cout<<"C";
  else if(hundreds==2)
   cout<<"CC";
  else if(hundreds==3)
   cout<<"CCC";
  else if(hundreds==4)
   cout<<"CD";
  else if(hundreds==5)
  cout<<"D";
  else if(hundreds==6)
   cout<<"DC";
  else if(hundreds==7)
   cout<<"DCC";
  else if(hundreds==8)
    cout<<"DCCC";
  else if(hundreds==9)
   cout<<"CM";

  if(tens==1)
  cout<<"X";
  else if(tens==2)
   cout<<"XX";
  else if(tens==3)
   cout<<"XXX";
  else if(tens==4)
   cout<<"XL";
  else if(tens==5)
  cout<<"L";
  else if(tens==6)
   cout<<"LX";
  else if(tens==7)
   cout<<"LXX";
  else if(tens==8)
    cout<<"LXXX";
  else if(tens==9)
   cout<<"XC";

   if(ones==1)
   cout<<"I";
  else if(ones==2)
   cout<<"II";
  else if(ones==3)
   cout<<"III";
  else if(ones==4)
   cout<<"IV";
  else if(ones==5)
  cout<<"V";
  else if(ones==6)
   cout<<"VI";
  else if(ones==7)
   cout<<"VII";
  else if(ones==8)
    cout<<"VIII";
  else if(ones==9)
   cout<<"IX";

return 0;

}



#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


bool isPowerOfThree(int n) {
       return fmod((log10(n) / log10(3)),1) == 0;
}

int main(){
      
      cout<<isPowerOfThree(27)<<endl;
      cout<<isPowerOfThree(12)<<endl;

      return 0;
}
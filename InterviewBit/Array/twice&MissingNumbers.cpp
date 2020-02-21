#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

/*
A == 2times 
B == missing
*/

vector<int> repeatedNumber(const vector<int> &V) {

    long long sum = 0;
   long long squareSum = 0;
   long long temp;
   for (int i = 0; i < V.size(); i++) {
       temp = V[i];
       sum += temp;
       sum -= (i + 1);
       squareSum += (temp * temp);
       squareSum -= ((long long)(i + 1) * (long long)(i + 1));
   }
   // sum = A - B
   // squareSum = A^2 - B^2 = (A - B)(A + B)
   // squareSum / sum = A + B
   squareSum /= sum;

   // Now we have A + B and A - B. Lets figure out A and B now. 
   int A = (int) ((sum + squareSum) / 2);
   int B = squareSum - A;

   vector<int> ret;
   ret.push_back(A);
   ret.push_back(B);
   return ret;
    
}


int main(){
    
    vector<int> vect{3,1,2,5,3};
    
    vector<int> ans = repeatedNumber(vect);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}
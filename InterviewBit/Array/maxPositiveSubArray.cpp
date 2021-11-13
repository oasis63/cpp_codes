#include<bits/stdc++.h>
using namespace std;

/*

Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous.
*/

vector<int> maxset(vector<int> &A) {

  int n = A.size();
  vector<int> ans;
  long long int lastSum = -1;
  vector<int> temp;

  long long int currSum = 0;
  
  int i=0;
  while(i<n && A[i]<0)
          i++;

  for(i=0;i<n;i++){
          if(A[i] >= 0){
              currSum += A[i];
              temp.push_back(A[i]);
          }else{
              if(currSum > lastSum){
                  lastSum = currSum;
                  ans = temp;
              }else if(currSum == lastSum && ans.size() < temp.size()){
                  ans = temp;
              }
              
              temp.clear();
              currSum=0;
          }
  }
  
   if(A[n-1] >= 0){
    if(currSum > lastSum){
        lastSum = currSum;
        ans = temp;
    }else if(currSum == lastSum && ans.size() < temp.size()){
        ans = temp;
    }
  }

  return ans;

}


int main(){
    
    // vector<ll> vect{1, 2, 5, -7, 2, 3};
    // vector<ll> vect{ 0, 0, -1, 0};
    vector<int> vect{756898537, -1973594324, -2038664370, -184803526, 1424268980};
    vector<int> ans = maxset(vect);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}
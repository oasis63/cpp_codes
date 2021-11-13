#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &A) {
    sort(A.begin(),A.end());

    int n = A.size(),sum=-1;

    vector<vector<int>> ans;

    for(int i=0;i<n-2;i++){
        // fix the smallest number
        int j = i+1,k=n-1;
        while(j<k){

            sum = A[i]+A[j]+A[k];

            if(sum==0){
                vector<int> temp {A[i],A[j],A[k]};

                bool flag = true;

                // checking the temp in the ans vector 
                for(int z=0;z<ans.size();z++){
                    if(ans[z][0] == A[i]){
                        if((ans[z][1]== A[j] && ans[z][2] == A[k]) || (ans[z][2]== A[j] && ans[z][1] == A[k]) ){
                            flag = false;
                            break;
                        }
                    }

                    if(ans[z][0] == A[j]){
                        if((ans[z][1]== A[i] && ans[z][2] == A[k]) || (ans[z][2]== A[k] && ans[z][1] == A[i]) ){
                            flag = false;
                            break;
                        }
                    }

                    if(ans[z][0] == A[k]){
                        if((ans[z][1]== A[j] && ans[z][2] == A[i]) || (ans[z][2]== A[i] && ans[z][1] == A[j]) ){
                            flag = false;
                            break;
                        }
                    }

                }

                if(flag){
                    ans.push_back(temp);

                }

            }

            if(sum > 0){
                k--;
            }else{
                j++;
            }
        }
    }

  return ans;
}

// more efficient code


vector<vector<int>> Efficient_threeSum(vector<int> &A) {
    sort(A.begin(),A.end());

    int n = A.size(),sum=-1;

    vector<vector<int>> ans;

    // fix the smallest element ..
    for(int i=0;i<n-2;i++){

        // skipping the duplicate elements
       if(i>0 && A[i] == A[i-1]){
            continue;
       }

        int j = i+1,k=n-1;
        while(j<k){
            sum = A[i] + A[j] + A[k];

            if(sum == 0){
                vector<int> temp{A[i],A[j],A[k]};
                ans.push_back(temp);

                // skip all the occurrence of duplicates
                j++;
                while(j<k && A[j] == A[j-1]){
                    j++;
                }
            }

            if(sum > 0)
                k--;
            else if(sum < 0)
                j++;

        }
    }

  return ans;
}



int main(){

    vector<int> vect {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = Efficient_threeSum(vect);

    for(int i=0;i<ans.size();i++){
      cout<<ans[i][0]<<" ";
      cout<<ans[i][1]<<" ";
      cout<<ans[i][2]<<endl;
    }

}




#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

bool checkSimilarSetBit(int a , int b){
    while (a && b){
        if((a&1) == 1 && (b&1) == 1){
            cout<<"common set bit " << endl;
            return true;
        }
        a = a >> 1;
        b = b >> 1;
    }
    cout<<"no common set bit"<<endl;
    return false;
}

int main(){

    int a = 3;
    int b = 8;

    bool flag = checkSimilarSetBit(a,b);
    
    cout << "a & b : " << (a & b) << endl;

    cout<<"flag : " << flag << endl;

    cout<<"\n Pairs " <<endl;

    vector<int> nums{1,3,8,48,10};
    // create all the pairs 

    int n = nums.size();

    for(int i = 0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<nums[i]<<"  " << nums[j] <<endl;
        }
        cout<<endl;
    }


    return 0;
}
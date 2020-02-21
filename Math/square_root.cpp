#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int sqrt(int A) {
    if(A==0)
        return 0;
    
    long   beg = 1,end = A,mid;
    long  ans = 0;
    while(beg <= end){
        mid = (beg + end)/2;
        
        if(mid*mid == A){
            ans =  mid;
            return ans;
        }else if(mid*mid < A){
            ans = mid;
            beg = mid  + 1 ;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}


int main(){
    
    cout<<sqrt(11)<<endl;
    cout<<sqrt(9)<<endl;

    return 0;
}
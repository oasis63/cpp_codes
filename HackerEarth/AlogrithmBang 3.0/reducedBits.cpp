#include<bits/stdc++.h>
using namespace std;

unsigned countBits(unsigned int number)
{
      // log function in base 2
      // take only integer part
      return (int)log2(number)+1;
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int q;cin>>q;
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;

        l--;
        r--;

        if(t==1){
            for(int i=l;i<=r;i++){
                a[i] = countBits(a[i]);
            }
        }else{
            int sum = 0;
            for(int i=l;i<=r;i++){
                sum += a[i];
            }
            cout<<sum<<endl;
        }



    }


}

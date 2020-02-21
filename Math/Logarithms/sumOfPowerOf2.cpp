#include<bits/stdc++.h>
using namespace std;

void solve(int n,int cnt){

    int count=cnt;

    double p = log2(n);
    int i_p = int(p);

    while(n!=1){
        int temp = pow(2,i_p);
        n-=temp;
        count++;

        p = log2(n);
        i_p = int(p);

        if(p==i_p){
            count++;
            break;
        }
    }

    cout<<count<<endl;

}


int main(){

    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        double p = log2(n);
        int i_p = int(p);

       // cout<<p<<endl;
       // cout<<i_p<<endl;

        if(i_p > 11){
            //solve

            if(p==i_p){
                cout<<n/2048<<endl;
            }else{
                //cout<<"second"<<endl;
                int count=n/2048;
                n=n%2048;       // value of n is now less than 2048

               // cout<<n<<endl;

                p = log2(n);
                i_p = int(p);

                if(p==i_p){
                    count++;
                    cout<<count<<endl;

                }else{
                    // value of n is now less than 2048
                    solve(n,count);
                }

            }


        }else if( p == i_p){
            cout<<1<<endl;
        }else{

            solve(n,0);

        }
    }

}

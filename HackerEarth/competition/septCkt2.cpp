    #include<bits/stdc++.h>
    using namespace std;

    const int mxm = 1e5+1;

    int main(){
        int hash[mxm]={0};

        int nB;cin>>nB;
        for(int i=0;i<nB;++i){
            int temp;cin>>temp;
            hash[temp]++;
        }

        int q;cin>>q;

        for(int i=0;i<q;i++){
            int temp; cin>>temp;

            int count=0;

            for(int i=temp;i<mxm;i+=temp){
                count += hash[i];
            }

            cout<<count<<endl;
        }
    }

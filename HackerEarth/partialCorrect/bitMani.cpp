#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fun1(priority_queue<ll,vector<ll>,greater<ll>>spq,ll m){
    ll ret=0;

    while(m>0 && !(spq.empty())){
        ll val = spq.top();
        ret=ret^val;
        spq.pop();
        m--;
    }

    return ret;

}

ll fun2(priority_queue<ll>gpq,ll p){
    ll ret=0;

    while(p>0 && !(gpq.empty())){
        ll val = gpq.top();
        ret=ret^val;
        gpq.pop();
        p--;
    }

    return ret;

}

template<typename T>
void print(T& pq){
    // iterator

    //pq.push(34);

    while(pq.size()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;cin>>t;
    while(t--){

        ll n,m,p,i,j,l,r;

        cin>>n>>m>>p;

        ll input[n];
        priority_queue<ll,vector<ll>,greater<ll>> spq;  // increasing order
        priority_queue<ll> gpq; // decreasing order

        for(i=0;i<n;i++){
            cin>>input[i];
        }

        ll ans=0;

        ll len=0;


        ll minLen = (m>p)?m:p;

        cout<<"MinLen : ";
        cout<<minLen<<endl;

        for(i=0;i<=n-minLen;i++){
            int con = minLen;
            while(con<n ){

                 for(j=i;(j<(i+con) && j<n);j++){
                    spq.push(input[j]);  // from smaller
                    gpq.push(input[j]);  // from larger
                    //cout<<"\t\t";
                    //cout<<input[j]<<" ";
                 }


                    ll f1=fun1(spq,m);
                    //cout<<"\nsmaller ";
                    //print(spq);

                    //cout<<"\nLarger ";
                    //print(gpq);

                    //cout<<"f1 : " << f1<<" " ;

                    ll f2=fun2(gpq,p);



                    //cout<<"f2 : " << f2<<" " ;

                    ll f = f1&f2;

                    //cout<<"f: " << f<<" " ;

                    if(f>ans){
                        ans=f;
                        l=i;
                        r=j;

                        len=j-i;

                    }
                    else if( f== ans){
                        if((j-i) > len){
                            len=j-i;
                        }
                    }

                    gpq = priority_queue <ll>();
                    spq = priority_queue <ll,vector<ll>,greater<ll>>();


                //cout<<endl;
                con++;
            }

        }


        cout<<(l+1)<<" " <<r<<" " << ans<<endl;

    }
}

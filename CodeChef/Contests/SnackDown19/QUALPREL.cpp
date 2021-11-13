#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool compare(ll a,ll b){
  if(a>b)
    return true;
  return false;
}

void print(ll arr[],ll n){
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    
    int tc;
    //cin>>tc;
     scanf("%d",&tc);   
    
    assert(tc>=1 && tc<=1000);

    while(tc-- >0){
        ll n,k;
        cin>>n>>k;
        assert(n>=1 && n<=100000);
        assert(k>=1 && k<=100000);

        ll nums[n];
        for(ll i=0;i<n;i++){
            //cin>>nums[i];
            scanf("%lld",&nums[i]);
            assert(nums[i]>=1 && nums[i]<=1000000000);
        }
        
        sort(nums,nums+n,compare);

        //print(nums,n);

        ll ans = k;

        ll level = nums[k-1];
        for(ll i=k;i<n;i++){
            if(nums[i] == level){
                ans++;
            }else{
                break;
            }
        }

        //cout<<ans<<endl;
        printf("%lld\n",ans);
    }

    return 0;
}



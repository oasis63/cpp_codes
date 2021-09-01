#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    int notes[] = {100,50,10,5,2,1};

    int ti,a;
    cin>>ti;
    while(ti--){
        cin>>a;
        int ans = 0;
        for(int i=0;i<6;i++){
            ans += a/notes[i];
            a = a%notes[i];
            if(a==0)
                break;
        }
        cout<<ans<<endl;
    }

    return 0;
}
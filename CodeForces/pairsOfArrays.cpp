#include<bits/stdc++.h>
using namespace std;

void input(int *arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void output(int *arr,int n){
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
}

int main(){

    int n,m;
    cin>>n;
    int boys[n];
    bool visitBoy[n];
    input(boys,n);
    cin>>m;
    int girls[m];
    bool visitGirl[m];
    input(girls,m);

    sort(boys,boys+n);
    sort(girls,girls+m);

    memset(visitBoy,true,sizeof(visitBoy));
    memset(visitGirl,true,sizeof(visitGirl));

    int pairs = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(abs(boys[i]-girls[j]) <= 1 && visitGirl[j]){
                pairs++;
                visitGirl[j] = false;
               // cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }

    cout<<pairs<<endl;

}

/*

4
1 4 6 2
5
5 1 5 7 9

3

4
1 2 3 4
4
10 11 12 13

0


5
1 1 1 1 1
3
1 2 3

2


*/

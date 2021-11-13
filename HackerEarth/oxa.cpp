#include<bits/stdc++.h>
using namespace std;

// generating all the subset in of a set

bool iBitSet(int n,int i){
    if((n & (1<<i)))
        return true;
    return false;
}

int solve(vector<int> subElems){

    int res = subElems[0];
    int turn = 0;

    int len = subElems.size();

    for(int i=1;i<len;i++){

        if(turn==0){
            res = res | subElems[i];
            turn = (turn+1)%3;
        }else if(turn==1){
            res = res^subElems[i];
            turn = (turn+1)%3;
        }else{
            res += subElems[i];
           // cout<<"  :  Addition Executed  : ";
            turn = (turn+1)%3;
        }

    }

    return res;
}


int subsets(int a[],int n){

    // number of subsets == pow(2,n)

    int oxa = -1;

    for(int i=1;i< (1<<n);i++){  // (1<<n) == pow(2,n)

        vector<int> subElems;

        for(int j=0;j<n;j++){
            if(iBitSet(i,j)){  // jth bit is set in i
               // cout<<a[j]<<" ";
                subElems.push_back(a[j]);
            }
        }

       int res = solve(subElems);

       subElems.clear();

       // cout<<"\t\t"<<res;


        if(res > oxa){
            oxa = res;
        }

        //cout<<endl;
    }

    return oxa;
}

int main(){

    int tc;cin>>tc;

    while(tc--){
        int n;
        string monk;
        cin>>monk;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++)
            cin>>input[i];
        int oxa = subsets(input,n);

        cout<<"\t\t"<<oxa;

        if(oxa%2==0 && monk=="Even"){
            cout<<"Monk"<<endl;
        }else if(oxa%2!=0 && monk=="Odd"){
            cout<<"Monk"<<endl;
        }else{
            cout<<"Mariam"<<endl;
        }
    }

//
//
//
//
//    int input[] = {4,5,1,2,10};
//    //int input[] = {1,2,3};
//    int n=5;
//
//    int oxa = subsets(input,n);
//    cout<<oxa<<endl;
}

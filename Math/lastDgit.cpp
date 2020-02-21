// no of divisors
#include<bits/stdc++.h>
using namespace std;

void printSet(set<int>s){

    set<int>::iterator itr = s.begin();

    while(itr!=s.end()){
        cout<<*itr<<" ";
        itr++;
    }

}

int main(){
    int n,p;
    cin>>n>>p;

    set<int> s;

    int i=1;

    while(1){
        int temp = (int)(pow(n,i))%10;
        i++;
        if(s.find(temp)!=s.end())
            break;
        s.insert(temp);
    }

    int len = s.size();

    int rem = p%len;

    if(len==1)
        cout<<n<<endl;
    else{
        if(rem==0)
            cout<<pow(n,len)<<endl;
        else
            cout<<pow(n,rem)<<endl;
    }



}

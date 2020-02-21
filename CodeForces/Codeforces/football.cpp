#include<bits/stdc++.h>
using namespace std;

int main(){
   string str;
   cin>>str;

   int n = str.length();

    int get=0;
    int count=0;

   for(int i=0;i<n;i++){
        count=1;
        int j=i+1;
        char ch=str[i];
        while(str[j]==ch && j<n){
            count++;
            j++;
        }

        if(count >= 7){
            get=1;
            cout<<"YES"<<endl;
            break;
        }
   }

   if(!get){
    cout<<"NO"<<endl;
   }
}

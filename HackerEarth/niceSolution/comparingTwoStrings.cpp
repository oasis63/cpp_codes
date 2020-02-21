#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;cin>>t;
   while(t--){
       char s1[100000]; scanf("%s",s1);
       char  s2[100000];scanf("%s",s2);


        sort(s1,s1+strlen(s1));
        sort(s2,s2+strlen(s2));

        int flag=1;

        for(int i=0;i<strlen(s1);i++){
            if(s1[i] != s2[i]){
                flag=0;
                break;
            }
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
   }

}

#include<bits/stdc++.h>
using namespace std;

int main(){

   int a=1;
   int b = 2;

   int tok = 1;

   int n=2;

   for(int i=0;i<n;i++){
         if(tok){
            for(int j=0;j<5;j++){
                printf("%d",a);
            }
            printf("%d\n",b);
            tok=0;
         }else{
            a=b;
            b++;
            printf("%d",b);
            for(int j=0;j<5;j++){
                printf("%d",a);
            }
            printf("\n");
            tok=1;
            a=b;
            b++;
         }
   }
}

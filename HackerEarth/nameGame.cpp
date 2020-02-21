#include<bits/stdc++.h>
using namespace std;

#define size 122

int prime[size];

void set_prime(){
    
    prime[0] = 0;
    prime[1] = 0;

   for(int i=2;i<=size;i++)
        prime[i]=1;         // considering all to be prime

   for(int i=2;i<=sqrt(size);i++){
        if(prime[i]==1){
            // setting 0 to multiples of this prime numbers
            for(int j=i*2;j<=size;j+=i)
                prime[j]=0;

        }
   }
   
   for(int i=2;i<65;i++)
    prime[i]=0;
 
   for(int i=91;i<97;i++)
    prime[i]=0;
    
  
   
}

int nearestPrime(int n){
    
    int left=-1;
    int right=-1;

    int i,j;
    
    
    int top = 122 ;
    int bottom = 65;


    for( i=n+1;i<=top;i++){
        if(prime[i]==1){
            break;
        }
            
    }

    for( j=n-1;j>=bottom;j--){
        if(prime[j]==1){
            break;
        }
    }   

     left = n-j;
     right = i-n;

    if(left==right){
        
        if((j>=65 && j<=90) || (j>=97 && j<=122))    
            return j;
        else 
           return i;
    
    }

    else if( left < right){
        if((j>=65 && j<=90) || (j>=97 && j<=122))    
            return j;
        else 
           return i;
    }
    
    else if( left > right){
        if((i>=65 && i<=90) || (i>=97 && i<=122))    
            return i;
        else 
           return j;
    }

}

int main(){

    set_prime();   // setting the prime number

    int t;cin>>t;

    while(t--){
        int len; cin>>len;

        string ans="";

        for(int i=0;i<len;i++){
            
            char tC;cin>>tC;
            
            int temp = tC;

            if(prime[temp]==1)
                ans+=tC;
            else {
                 char c = (char)nearestPrime(temp);
                 ans += c;
            }

        }

        cout<<ans<<endl;

    }
}

/*  to access an array element time complexity is 
    O(1). so we have entered the  prime numbes in an array 

    so that it can be easily be accessed from the array */


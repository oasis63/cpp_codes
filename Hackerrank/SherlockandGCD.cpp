#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}


string solve(vector<int> vect){

    int n = vect.size();

    int g = 0;

    for(int i=0;i<n;i++){
      g = gcd(g,vect[i]);
    }

    if(g==1)
        return "YES";

    return "NO";
}


int main(){
    
    int tc;
    cin>>tc;

    while(tc--){
        int n;cin>>n;
        vector<int> vect(n);
        int g = 0;
        int elem;
        for(int i=0;i<n;i++){
           cin>>elem;
           g = gcd(g,elem);
        }
        if(g==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    

    return 0;
}



/*

 if gcd of a , b i.e., GCD(a,b) is 1 , 
 then GCD(a,b,c,e,x,y,z ..)   will always be 1


*/



/*

Sample Input

3
3
1 2 3
2
2 4
3
5 5 5


Sample Output

YES
NO
NO





*/
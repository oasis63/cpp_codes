#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int isNumber(const string A) {

    string str = A;
    int n = str.length();
    int i=0;
    while(i<n && str[i]==' '){ // removing the leading spaces
        i++;
    }
    int j=n-1;
    while(j>=0 && str[j]==' '){  // removing trailing spaces
        j--;
    }
    str = str.substr(i,j-i+1);

    n = str.length();

    if(n==0)
        return 0;

    bool e_f = false;   // exponent ->  e
    bool b_p = false;  //  point   ->  .

    for(int i=0;i<n;i++){
        char c = str[i];
        if(c>= '0' && c<= '9'){
            b_p = false;
            continue;
        }
        if(c=='.'){
            b_p = true;
            if(e_f)     // point(.) should not come just after e
                return 0;
            else
                continue;
        }

        if(c=='e'){
            if(b_p)   // exponent(e) should not come just after point(.)
                return 0;
            e_f = true;
            continue;
        }

        if(c=='-' && (i==0 || e_f == true))
            continue;

        return 0;
    }

    if(b_p)
        return 0;

    return 1;
}



int main(){

    cout<<isNumber("0.1")<<endl;
    cout<<isNumber("1.e1")<<endl;
    cout<<isNumber("10.33e10")<<endl;
    cout<<isNumber("0.0333")<<endl;

	return 0;
}

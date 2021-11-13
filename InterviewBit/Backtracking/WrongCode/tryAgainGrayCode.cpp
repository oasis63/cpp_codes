#include<bits/stdc++.h>
using namespace std;

/*
Not a correct solution
*/

void grayUtil(string str,int index){

    cout<<"\t"<<str<<endl;

    if(index<0)
        return;

    cout<<index<<endl;
    for(int i=index;i>=0;i--){
        char c = str[i];
        cout<<"\t"<<i<<endl;
        if(str[i] == '0')
            str[i] = '1';
        else
            str[i]='0';
        grayUtil(str,index-1);

        str[i] = c;
    }


}

void grayCode(int n){
    string str;

    for(int i=0;i<n;i++){
        str.push_back('0');
    }
    int index = str.length()-1;
    grayUtil(str,index);
}

int main(){

    grayCode(2);

}

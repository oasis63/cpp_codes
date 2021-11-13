#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

char digit(int n){

    switch(n){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return '0';
    }

}

pair<char,int> digitSubtract(char n1,char n2,int borrow){

    int num1 = n1 - '0';
    int num2 = n2 - '0';

    // cout<<num1<<" "<<num2<<" "<<borrow<<" ";

    num1 = num1 - borrow;

    if(num1 < num2){
        borrow = 1;
        num1 += 10;
    }else{
        borrow = 0;
    }

    int diff = num1 - num2;

    // cout<<diff<<endl;

    // cout<<" diff : "<<diff<<" ";

    char n =  digit(diff);

    // cout<<"n : "<<n<<" borrow : "<<borrow<<endl;

    return make_pair(n,borrow);
}

void subtractStringNums(string str1,string str2){

    string difference="";

    int len1 = str1.length();
    int len2 = str2.length();

    string num1,num2;
    char lastChar = '0';

    if(len1 < len2){
        num1 = str2;
        num2 = str1;

        int temp = len1;
        len1 = len2;
        len2 = temp;

        lastChar = '-';

    }else if(len1 == len2  && str1 < str2){

        num1 = str2;
        num2 = str1;

        lastChar = '-';

    }else{

        num1 = str1;
        num2 = str2;
    }


    int borrow=0;
    int i=len1-1,j=len2-1;


    for(i=len1-1,j=len2-1;i>=0 && j>=0;i--,j--){
        // cout<<"\t"<<i<<" "<<j<<endl;
        pair<char,int> ret =  digitSubtract(num1[i],num2[j],borrow);
        // cout<<ret.first<<endl;
        difference += ret.first;
       // cout<<"\t"<<difference<<endl;
        borrow =  ret.second;
    }

    if(i>=0){
        while(i>=0){
            //  cout<<"\t\t"<<i<<" "<<borrow<<endl;
            pair<char,int> ret = digitSubtract(num1[i],'0',borrow);
            difference += ret.first;
            borrow =  ret.second;

            i--;
        }
    }

   if(j>=0){

        while(j>=0){
             // cout<<"\t\t\t"<<j<<" "<<borrow<<endl;
            pair<char,int> ret =  digitSubtract(num2[j],'0',borrow);
            difference += ret.first;
            borrow =  ret.second;

            j--;
        }
   }


   /* if(borrow==1)
        difference+= '1';*/

   if(lastChar == '-')
        difference += lastChar;


    reverse(difference.begin(),difference.end());

    cout<<difference<<endl;
}


int main(){

   string num1="438";
   string num2="63";

    // string num1="393";
    // string num2="443";


    subtractStringNums(num1,num2);



    return 0;
}

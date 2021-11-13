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

pair<char,int> digitSum(char n1,char n2,int carry){

    int num1 = n1 - '0';
    int num2 = n2 - '0';

    cout<<num1<<" "<<num2<<" "<<carry<<" ";

    int sum = num1 + num2 + carry;

    cout<<sum<<endl;

    int dg = sum%10;
    int c = sum/10;


    char n =  digit(dg);

    return make_pair(n,c);
}

void addStringNums(string num,string diff){

    string sum="";

    int len1 = num.length();
    int len2 = diff.length();

    int carry=0;
    int i=len1-1,j=len2-1;


    for(i=len1-1,j=len2-1;i>=0 && j>=0;i--,j--){
        // cout<<"\t"<<i<<" "<<j<<endl;
        pair<char,int> ret =  digitSum(num[i],diff[j],carry);
        carry =  ret.second;
        sum += ret.first;
    }

    if(i>=0){
        while(i>=0){
            //  cout<<"\t\t"<<i<<" "<<carry<<endl;
            pair<char,int> ret = digitSum(num[i],'0',carry);
            carry =  ret.second;
            sum += ret.first;

            i--;
        }
    }

   if(j>=0){

        while(j>=0){
             // cout<<"\t\t\t"<<j<<" "<<carry<<endl;
            pair<char,int> ret =  digitSum(diff[j],'0',carry);
            carry =  ret.second;
            sum += ret.first;

            j--;
        }
   }



    if(carry==1)
        sum+= '1';

    reverse(sum.begin(),sum.end());

    cout<<sum<<endl;
}


int main(){

//    string num1="438";
//    string num2="63";

    string num1="98797979779124354544544353";
    string num2="97897897893454354355453543";


    addStringNums(num1,num2);



    return 0;
}

#include<iostream>
using namespace std;


int main() 
{
    string str;
    cin >> str;
    int i;

    str.erase(0,2);

    i=str.empty();  // str.empty()  returns 1 if the string is empty else 0 ;

    cout << str << endl;
    cout<<"\n"<<i<<endl;
}

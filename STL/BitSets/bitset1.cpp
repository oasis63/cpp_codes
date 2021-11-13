#include<bits/stdc++.h>
using namespace std;

int main(){

    string num = "1000";

    //bitset<32> b(string("100000"));

    /*bitset<32> bitSet1;
    bitSet1 = 0; */

    bitset<32> b(num);

    b.flip(2);    // index where u want to flip the bit

    string str = b.to_string();

    cout<<str<<endl;

    // bitset to integer value

    int value = b.to_ulong();
    cout<<value<<endl;
}

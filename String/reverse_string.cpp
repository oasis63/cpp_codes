//Reversing a string
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string to be reversed: ";
    getline(cin, str);

    cout << str << " when reversed, is ";

    reverse(str.begin(),str.end());

    cout << str << endl;

    return 0;
}

//Reversing a string
#include <iostream>

using namespace std;

int main()
{
    string str;
    cout << "Enter a string to be reversed: ";
    getline(cin, str);

    int len = str.length();
    
    cout << len << endl;

    return 0;
}

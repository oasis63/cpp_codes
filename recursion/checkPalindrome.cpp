#include <iostream>
#include<string.h>
using namespace std;

/*
 base case

    length of 0 ans 1 is palindrome

    sample input :

    racecar

    ninja

 */

bool checkPalindrome(char *str){
    int len = strlen(str);
     if(len == 0 || len == 1)
        return true;
     else if(str[0] != str[len-1])
        return false;
    str++;   // removing the first element
//    len = strlen(str);
    str[len-2] = '\0';   // removing the last element
    return checkPalindrome(str);
}



int main() {
    char input[50];
    cin >> input;

    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

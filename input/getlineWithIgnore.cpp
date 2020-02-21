#include <bits/stdc++.h>
using namespace std;

int main()
{
    // if you're using getline after cin >> something, 
    // you need to flush the newline character out of the buffer in between. 
    // You can do it by using cin.ignore()

    // It would be something like this:

    string msg;
    cout << "Type your message: ";
    cin.ignore(); 
    getline(cin, msg);

    cout<<"Entered string :"<<msg<<endl;

    // This happens because the >> operator leaves a newline \n character in the input buffer.
    // This may become a problem when you do unformatted input, 
    // like getline(), which reads input until a newline character is found. This happening, 
    // it will stop reading immediatly, 
    // because of that \n that was left hanging there in your previous operation.

}
#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 5, 3, 2};

    /*for(int i : a)
        cout<<i<<" " ; */

    for (auto i : a) // similar to Enhanced Loop
        cout << i << " ";

} // return mid;

// Array template has fixed size
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l1{1, 2, 0, 9, 3, 2, 4};

    /* int n;
       cout<<"\nEnter the number of elements \n";
       cin>>n; */

    list<int>::iterator il = l1.begin();

    while (il != l1.end()) {
        cout << *il << " ";

        il++;
    }

    cout << "\nSize = " << l1.size() << endl;

    l1.push_back(99);
    l1.push_front(-1);

    l1.reverse();

    cout << endl;

    il = l1.begin();

    while (il != l1.end()) {
        cout << *il << " ";
        il++;
    }

    cout << endl;

    // l1.remove(0); // removes the particular value passed to it

    // l1.clear();  //clears the list

    l1.sort(); // sorts the list

    il = l1.begin();

    while (il != l1.end()) {
        cout << *il << " ";
        il++;
    }

    cout << endl;

    /*l1.pop_front();  // deletes the front element
    l1.pop_back(); */  // deletes the back element
}

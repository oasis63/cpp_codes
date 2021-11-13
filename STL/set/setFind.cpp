#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> example = {1, 2, 3, 4};

    auto search = example.find(2);

    if(search != example.end()) {
        cout << "Found " << (*search) << '\n';
    }
    else {
        cout << "Not found\n";
    }
}

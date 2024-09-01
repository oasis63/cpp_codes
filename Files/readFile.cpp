#include <bits/stdc++.h>
using namespace std;

int main() {

    // filestream variable file
    fstream file;
    string word, t, q, filename;
    int n;

    filename = "input.txt";

    file.open(filename);

    while (file >> n) {
        cout << n << endl;
    }

    return 0;
}

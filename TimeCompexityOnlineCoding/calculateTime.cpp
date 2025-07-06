#include <bits/stdc++.h>
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    // Operation you want to measure
    for (int i = 0; i < 1000000; ++i) {
        // Some operation
    }

    auto end = chrono::high_resolution_clock::now();

    // chrono::duration<double> duration = end - start;
    // cout << "Time taken: " << duration.count() << " seconds" << endl;

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void showpq(priority_queue<vector<int>> gq) {
    // priority_queue<pair<int, int>> g = gq;
    while (!gq.empty()) {
        vector<int> p = gq.top();
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << "  ";
        }
        cout << endl;
        gq.pop();
    }
    cout << '\n';
}

// bool compare(pair<int, int> p1, pair<int, int> p2) {
//     return p1.second > p2.second;
// }

int main() {
    priority_queue<vector<int>> pq;

    // pq.push(make_pair(10, 2));
    pq.push({10, 2});
    // pq.push(make_pair(30, 1));
    pq.push({30, 1});
    pq.push({20, 4});
    pq.push({5, 2});
    pq.push({1, 1});

    showpq(pq);
    cout << "pq.size() : " << pq.size() << endl;

    pq.pop({10, 2});

    showpq(pq);

    return 0;
}

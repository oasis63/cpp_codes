#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

void printPq(priority_queue<int> pq) {
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

void printPq2(priority_queue<int, vector<int>, greater<int>> pq) {
  while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
}

int main() {
  priority_queue<int> mxHeap;                              // mxHeap
  priority_queue<int, vector<int>, greater<int>> minHeap;  // minHeap

  vector<int> vect = {1, 2, 3, 4, 5};
  // vector<int> vect = {1, 2, 3};
  int n = vect.size();

  cout << "n : " << n << endl;

  for (int i = 0; i < n; i++) {
    int v = vect[i];

    cout << "------Inserting value ------: " << v << endl;
    if (mxHeap.empty() || v <= mxHeap.top()) {
      mxHeap.push(v);
    } else {
      minHeap.push(v);
    }

    cout << "MaxHeap --> ";
    printPq(mxHeap);

    cout << "MinHeap --> ";
    printPq2(minHeap);

    // balance the tree .. left - right subtree <= 1

    if (mxHeap.size() > minHeap.size() + 1) {
      minHeap.push(mxHeap.top());
      mxHeap.pop();
    } else if (minHeap.size() > mxHeap.size()) {
      mxHeap.push(minHeap.top());
      minHeap.pop();
    }

    cout << "After Rebalancing both the trees " << endl;

    cout << "MaxHeap --> ";
    printPq(mxHeap);

    cout << "MinHeap --> ";
    printPq2(minHeap);

    // find the median

    double median = 0.0;

    // even number of elements
    if ((i + 1) % 2 == 0) {
      median = (minHeap.top() + mxHeap.top()) / 2.0;
      cout << "Even ";
      cout << "i : " << i << " size : " << (i + 1) << " median : " << median
           << endl;
    } else {  // odd number of elements
      median = (double)mxHeap.top() * 1.0;
      cout << "Odd ";
      cout << "i : " << i << " size : " << (i + 1) << " median : " << median
           << endl;
    }
  }

  return 0;
}
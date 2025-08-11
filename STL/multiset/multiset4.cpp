#include <bits/stdc++.h>
using namespace std;

int main() {
  multiset<int> ms;

  // Insert elements (duplicates allowed)
  ms.insert(10);
  ms.insert(5);
  ms.insert(20);
  ms.insert(10);  // duplicate

  // Display elements
  cout << "Elements in multiset: ";
  for (int x : ms) cout << x << " ";
  cout << "\n";

  // Count occurrences
  cout << "Count of 10: " << ms.count(10) << "\n";

  // Find element
  auto it = ms.find(10);
  if (it != ms.end())
    cout << "Found 10\n";

  // Erase one occurrence of 10
  ms.erase(ms.find(10));

  cout << "After erasing one 10: ";
  for (int x : ms) cout << x << " ";
}

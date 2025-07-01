#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long

int main() {
  bitset<3> bs(3);
  bitset<3> bs1(5);

  cout << bs << endl;

  cout << bs.test(0) << endl;
  cout << bs.test(1) << endl;
  cout << bs.test(2) << endl;

  cout << (bs & bs1) << endl;

  cout << bs.count() << endl;

  return 0;
}
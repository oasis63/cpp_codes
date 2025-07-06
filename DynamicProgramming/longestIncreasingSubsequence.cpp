#include <bits/stdc++.h>
using namespace std;

int findLIS(int arr[], int n) {
  int *lis;
  lis = new int[n];
  for (int i = 0; i < n; i++) lis[i] = 1;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) lis[i] = max(lis[i], lis[j] + 1);
    }
  }

  int ans = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (lis[i] > ans) ans = lis[i];
  }

  delete[] lis;

  return ans;
}

int main() {
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = 16;

  int ans = findLIS(arr, n);

  cout << ans << endl;
}

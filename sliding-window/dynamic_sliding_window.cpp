#include <bits/stdc++.h>
using namespace std;

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}

class Data {
 public:
  int start;
  int end;
  int len;
  Data(int s, int e, int l) {
    this->start = s;
    this->end = e;
    this->len = l;
  }
};

int main() {
  vector<int> vect = {3, 1, 1, 1, 5, 1, 2, 1};
  int target = 3;

  int n = vect.size();

  // using sliding window ... find the possible subarray sum

  int start = 0;
  int end = 0;

  vector<Data> data;

  int curr_sum = 0;

  while (end < n) {
    curr_sum += vect[end];

    // shrink the window from left side
    while (curr_sum > target && start <= end) {
      curr_sum -= vect[start];
      start++;
    }

    if (curr_sum == target) {
      int len = end - start + 1;
      data.push_back(Data(start, end, end - start + 1));
    }

    end++;
  }

  for (Data d : data) {
    cout << d.start << "  " << d.end << "   " << d.len << endl;
  }

  return 0;
}
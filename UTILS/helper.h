// helper.h
#ifndef HELPER_H
#define HELPER_H

#include <bits/stdc++.h>
using namespace std;

#define printVect(a)                 \
  for (auto x : a) cout << x << " "; \
  cout << endl
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>

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

inline int power(int a, int b) {
  int x = 1;
  while (b) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}

vector<int> parseIntVector(string s) {
  vector<int> result;
  string num = "";
  for (char c : s) {
    if (isdigit(c) || c == '-') {
      num += c;
    } else if (!num.empty()) {
      result.push_back(stoi(num));
      num = "";
    }
  }
  if (!num.empty()) result.push_back(stoi(num));
  return result;
}

vector<string> parseStringVector(const string& s) {
  vector<string> result;
  string word = "";
  bool insideQuotes = false;

  for (char c : s) {
    if (c == '"') {
      insideQuotes = !insideQuotes;
      if (!insideQuotes && !word.empty()) {
        result.push_back(word);
        word = "";
      }
    } else if (insideQuotes) {
      word += c;
    }
  }

  return result;
}

// Function declarations
template <typename T>
void copyVector(const vector<T>& source, vector<T>& destination) {
  destination = source;
}

template <typename T>
void clearVector(vector<T>& vec) {
  vec.clear();
}

template <typename T>
void printVector(const vector<T>& vec) {
  for (const T& item : vec) {
    cout << item << " ";
  }
  cout << endl;
}

template <typename T>
void print2DVector(const vector<vector<T>>& matrix) {
  for (const auto& row : matrix) {
    for (const T& item : row) {
      cout << item << " ";
    }
    cout << endl;
  }
  cout << "--------------------" << endl;
}

#endif  // HELPER_H

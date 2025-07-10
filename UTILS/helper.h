// helper.h
#ifndef HELPER_H
#define HELPER_H

#include <bits/stdc++.h>

// #include "compete_helper.h"
using namespace std;

#define printVect(a)                 \
  for (auto x : a) cout << x << " "; \
  cout << endl

#define printPairVect(a) \
  for (auto x : a) cout << x.F << " " << x.S << endl

#define printVectRange(a, x, y)                    \
  for (int i = x; i < y; i++) cout << a[i] << " "; \
  cout << endl

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()

#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>

#define MOD 1000000007

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
  cout << endl;
}

template <typename K, typename V>
void printMap(const unordered_map<K, V>& mp) {
  for (const auto& pair : mp) {
    cout << pair.first << " : " << pair.second << "\n";
  }
  cout << endl;
}

// 1D VECTOR TO PARSE INPUT OF ALL TYPES OF DATA TYPE
template <typename T>
vector<T> parseVector(const string& s) {
  vector<T> result;

  if constexpr (is_same<T, char>::value) {
    // Character parsing
    for (char c : s) {
      if (isalpha(c))
        result.push_back(c);
    }
  } else if constexpr (is_integral<T>::value) {
    // Integer parsing
    string num = "";
    for (char c : s) {
      if (isdigit(c) || c == '-') {
        num += c;
      } else if (!num.empty()) {
        result.push_back(static_cast<T>(stoi(num)));
        num = "";
      }
    }
    if (!num.empty()) result.push_back(static_cast<T>(stoi(num)));
  } else if constexpr (is_floating_point<T>::value) {
    // Float/double parsing
    string num = "";
    for (char c : s) {
      if (isdigit(c) || c == '-' || c == '.') {
        num += c;
      } else if (!num.empty()) {
        result.push_back(static_cast<T>(stod(num)));
        num = "";
      }
    }
    if (!num.empty()) result.push_back(static_cast<T>(stod(num)));
  }

  return result;
}

/*
ex:

 string intInput = "[1, -2, 3]";
  string floatInput = "[1.5, -2.3, 0.0]";
  string charInput = "[a, b, c]";

  vector<int> ints = parseVector<int>(intInput);
  vector<float> floats = parseVector<float>(floatInput);
  vector<double> doubles = parseVector<double>(floatInput);
  vector<char> chars = parseVector<char>(charInput);

*/

template <typename T>
vector<vector<T>> parse2DVector(const string& s) {
  vector<vector<T>> result;
  vector<T> currentRow;
  string token = "";
  bool insideRow = false;

  for (char c : s) {
    if constexpr (is_same<T, char>::value) {
      if (c == '[') {
        insideRow = true;
        currentRow.clear();
      } else if (c == ']') {
        if (!currentRow.empty()) result.push_back(currentRow);
        insideRow = false;
      } else if (insideRow && isalpha(c)) {
        currentRow.push_back(c);
      }
    } else if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
      if (c == '[') {
        insideRow = true;
        currentRow.clear();
      } else if ((isdigit(c) || c == '-' || c == '.') && insideRow) {
        token += c;
      } else if ((c == ',' || c == ' ' || c == ']') && !token.empty()) {
        if constexpr (is_same<T, int>::value)
          currentRow.push_back(stoi(token));
        else
          currentRow.push_back(static_cast<T>(stod(token)));
        token = "";
        if (c == ']') {
          result.push_back(currentRow);
          insideRow = false;
        }
      }
    }
  }

  return result;
}

#endif  // HELPER_H

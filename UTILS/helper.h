// helper.h
#ifndef HELPER_H
#define HELPER_H

#include <bits/stdc++.h>

// #include "compete_helper.h"
using namespace std;

#define printVect(a)                 \
  for (auto x : a) cout << x << " "; \
  cout << "\n"

#define printPairVect(a) \
  for (auto x : a) cout << x.F << " " << x.S << "\n"

#define printVectRange(a, x, y)                    \
  for (int i = x; i < y; i++) cout << a[i] << " "; \
  cout << "\n"

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
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()

#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>

// #define MOD 1000000007

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
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
    if (b & 1)
      x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}

// define input_output_files
void set_io_files(const string& inputFile, const string& outputFile) {
  // freopen(inputFile.c_str(), "r", stdin);
  // freopen(outputFile.c_str(), "w", stdout);

  FILE* in = freopen(inputFile.c_str(), "r", stdin);
  if (!in) {
    perror(("freopen " + inputFile + " failed").c_str());
    exit(EXIT_FAILURE);
  }

  FILE* out = freopen(outputFile.c_str(), "w", stdout);
  if (!out) {
    perror(("freopen " + outputFile + " failed").c_str());
    exit(EXIT_FAILURE);
  }
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
  cout << "\n";
}

template <typename T>
void printVectorWithIndices(const vector<T>& vec) {
  for (int i = 0; i < (int)vec.size(); i++) {
    cout << i << " " << vec[i] << "\n";
  }
  cout << "\n";
}

template <typename T>
void print2DVector(const vector<vector<T>>& matrix) {
  for (const auto& row : matrix) {
    for (const T& item : row) {
      cout << item << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

template <typename MapType>
void printMap(const MapType& mp) {
  for (const auto& pair : mp) {
    cout << pair.first << " : " << pair.second << "\n";
  }
  cout << "\n";
}

// 1D VECTOR TO PARSE INPUT OF ALL TYPES OF DATA TYPE
template <typename T>
vector<T> parseVector(const string& s) {
  vector<T> result;
  string token = "";
  bool insideQuote = false;
  char quoteChar = '\0';

  try {
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];

      // Case 1: T is char
      if constexpr (is_same<T, char>::value) {
        if (c == '\'' || c == '"') {
          if (!insideQuote) {
            insideQuote = true;
            quoteChar = c;
          } else if (quoteChar == c) {
            insideQuote = false;
          } else {
            throw runtime_error("Mismatched quote character at position " + to_string(i));
          }
        } else if (insideQuote) {
          result.push_back(c);
        }
      }

      // Case 2: T is integral or floating point
      else if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
        if (isdigit(c) || c == '-' || c == '.') {
          token += c;
        } else if (!token.empty()) {
          try {
            if constexpr (is_same<T, int>::value)
              result.push_back(stoi(token));
            else if constexpr (is_same<T, float>::value)
              result.push_back(stof(token));
            else
              result.push_back(stod(token));  // for double or long double
          } catch (const invalid_argument&) {
            throw runtime_error("Invalid number token: '" + token + "' at position " + to_string(i));
          } catch (const out_of_range&) {
            throw runtime_error("Number out of range: '" + token + "' at position " + to_string(i));
          }
          token = "";
        }
      }

      // Case 3: T is string
      else if constexpr (is_same<T, string>::value) {
        if (c == '"' || c == '\'') {
          if (!insideQuote) {
            insideQuote = true;
            quoteChar = c;
          } else if (quoteChar == c) {
            insideQuote = false;
            result.push_back(token);
            token = "";
          } else {
            throw runtime_error("Mismatched quote character at position " + to_string(i));
          }
        } else if (insideQuote) {
          token += c;
        }
      }
    }

    // Final cleanup
    if (!token.empty()) {
      if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
        try {
          if constexpr (is_same<T, int>::value)
            result.push_back(stoi(token));
          else if constexpr (is_same<T, float>::value)
            result.push_back(stof(token));
          else
            result.push_back(stod(token));
        } catch (const exception& e) {
          throw runtime_error("Final number parse error: " + string(e.what()));
        }
      }
    }

    if constexpr (is_same<T, char>::value || is_same<T, string>::value) {
      if (insideQuote) {
        throw runtime_error("Unclosed quote in input string.");
      }
    }

    return result;
  } catch (const exception& e) {
    cerr << "Parsing Error: " << e.what() << "\n";
    return {};
  }
}

template <typename T>
vector<vector<T>> parse2DVector(const string& s) {
  vector<vector<T>> result;
  vector<T> currentRow;
  string token = "";
  bool insideRow = false;
  bool insideQuote = false;
  char quoteChar = '\0';

  try {
    for (size_t i = 0; i < s.size(); ++i) {
      char c = s[i];

      // Case 1: Char or String Type
      if constexpr (is_same<T, char>::value || is_same<T, string>::value) {
        if (c == '[') {
          insideRow = true;
          currentRow.clear();
        } else if ((c == '\'' || c == '"')) {
          if (!insideQuote) {
            quoteChar = c;
            insideQuote = true;
            token.clear();  // prepare for new token
          } else if (quoteChar == c) {
            insideQuote = false;
            if constexpr (is_same<T, char>::value)
              currentRow.push_back(token[0]);
            else
              currentRow.push_back(token);
            token.clear();
          } else {
            throw runtime_error("Mismatched quote at position " + to_string(i));
          }
        } else if (insideQuote) {
          token += c;
        } else if (c == ']') {
          if (!currentRow.empty()) {
            result.push_back(currentRow);
            currentRow.clear();
          }
          insideRow = false;
        }
      }

      // Case 2: Numeric Types
      else if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
        if (c == '[') {
          insideRow = true;
          currentRow.clear();
          token.clear();
        } else if ((isdigit(c) || c == '-' || c == '.') && insideRow) {
          token += c;
        } else if ((c == ',' || c == ' ' || c == ']') && !token.empty()) {
          try {
            if constexpr (is_same<T, int>::value)
              currentRow.push_back(stoi(token));
            else if constexpr (is_same<T, float>::value)
              currentRow.push_back(stof(token));
            else
              currentRow.push_back(stod(token));
          } catch (...) {
            throw runtime_error("Invalid numeric token: " + token);
          }
          token.clear();

          if (c == ']') {
            result.push_back(currentRow);
            currentRow.clear();
            insideRow = false;
          }
        }
      }
    }

    if (!token.empty() && (is_integral<T>::value || is_floating_point<T>::value)) {
      // Handle any trailing token not yet pushed
      if constexpr (is_same<T, int>::value)
        currentRow.push_back(stoi(token));
      else if constexpr (is_same<T, float>::value)
        currentRow.push_back(stof(token));
      else
        currentRow.push_back(stod(token));
      result.push_back(currentRow);
    }

    if (insideQuote)
      throw runtime_error("Unclosed quote in input.");

    return result;
  } catch (const exception& e) {
    cerr << "Parsing Error: " << e.what() << "\n";
    return {};
  }
}

#endif  // HELPER_H

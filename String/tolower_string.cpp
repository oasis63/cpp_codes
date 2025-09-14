#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  string m_str = "HeLLo WorlD";
  string str = m_str;

  transform(str.begin(), str.end(), str.begin(), ::tolower);

  cout << "Original string : " << m_str << endl;
  cout << "To Lower case string : " << str << endl;

  return 0;
}
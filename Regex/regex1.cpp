#include <bits/stdc++.h>

#include "UTILS/helper.h"
using namespace std;

int main() {
  set_io_files("input.txt", "output.txt");

  string text = "My email is example@test.com";

  // Regex pattern for a simple email
  regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-z]{2,})");

  if (regex_search(text, pattern)) {
    cout << "Email found!" << endl;
  } else {
    cout << "No email found!" << endl;
  }

  regex r("abc");
  cout << regex_match("abc", r);   // true
  cout << regex_match("zabc", r);  // false

  regex r("abc");
  cout << regex_search("zabc", r);  // true

  string text = "cat rat bat mat";
  regex r("[a-z]+at");

  auto words_begin = sregex_iterator(text.begin(), text.end(), r);
  auto words_end = sregex_iterator();

  for (auto it = words_begin; it != words_end; ++it) {
    cout << it->str() << endl;
  }

  return 0;
}
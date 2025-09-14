#include <iostream>
using namespace std;

// Forward declarations (instead of header file)
void greet();
void farewell();

int main() {
  greet();     // call function from file1.cpp
  farewell();  // call function from file1.cpp
  return 0;
}

/*
How to run :

g++ import_file1.cpp import_file2.cpp -o program
./program



*/

#include <iostream>
using namespace std;
class ExceptionTest {
  static int count;
  int number;
public:
  ExceptionTest() {
    count++;
    number = count;
    cout << "Constructing the object: " << number << endl;
    if(number == 3)
       throw 25;
  }
  ~ExceptionTest() { cout << "Destructing the object: " << number << endl; }
};
int ExceptionTest::count = 0;
int main() {
  try {
    ExceptionTest test[4];
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
  return 0;
}
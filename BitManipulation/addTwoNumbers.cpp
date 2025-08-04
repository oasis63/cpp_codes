class Solution {
 public:
  int getSum(int a, int b) {
    // int carry;
    // while (b != 0) {
    //     carry = a & b;
    //     a = a ^ b;
    //     b = carry << 1;
    // }
    // return a;
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
  }
};
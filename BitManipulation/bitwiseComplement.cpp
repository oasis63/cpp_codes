class Solution {
 public:
  int bitwiseComplement(int n) {
    if (n == 0)
      return 1;  // edge case

    int mask = 0;
    int temp = n;

    // Create a mask with all bits set to 1 up to the most significant bit of n
    while (temp > 0) {
      mask = (mask << 1) | 1;
      temp >>= 1;
    }

    // XOR with mask to flip bits
    return n ^ mask;
  }
};

/*

Note:

ex:  5  -->>   101
    mask -->   111
complement --> 010


so while calculating ,
we are justa adding 1 to the mask , based on number of bits in the binary form of the given number


*/
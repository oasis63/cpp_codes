class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    // majority in a group --->  boyer-moore voting algorithm
    int candidate = -1;
    int count = 0;

    for (int elem : nums) {
      if (count == 0) {
        candidate = elem;
      }

      if (elem == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }
};
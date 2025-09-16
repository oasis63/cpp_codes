// 2197. Replace Non-Coprime Numbers in Array

typedef long long ll;
class Solution {
 public:
  int gcd(int a, int b) {
    if (a == 0) {
      return b;
    }
    return gcd(b % a, a);
  }

  int lcm(int a, int b) {
    int g = gcd(a, b);
    ll p = (ll)a * b;
    int l = p / g;
    return l;
  }

  bool isCoPrime(int a, int b) {
    int g = gcd(a, b);
    return g == 1;
  }

  vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<int> stk;
    int len = nums.size();

    stk.push(nums[0]);

    for (int i = 1; i < len; i++) {
      int tp = stk.top();
      int curr = nums[i];

      if (isCoPrime(tp, curr)) {
        stk.push(curr);
      } else {
        // Non-CoPrime
        // remove the top element
        stk.pop();
        int l = lcm(tp, curr);
        stk.push(l);

        while (stk.size() > 1) {
          int tp1 = stk.top();
          stk.pop();

          int tp2 = stk.top();
          stk.pop();

          if (isCoPrime(tp1, tp2)) {
            stk.push(tp2);
            stk.push(tp1);

            break;
          } else {
            l = lcm(tp1, tp2);
            stk.push(l);
          }
        }
      }
    }

    vector<int> ans;

    while (!stk.empty()) {
      ans.push_back(stk.top());
      // ans.emplace_front(stk.top());
      stk.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int mapValue[50] = {0};

  public:
    int climbStairs(int n) {
        mapValue[0] = 1;
        mapValue[1] = 1;
        mapValue[2] = 2;
        for (int i = 3; i <= n; i++) {
            mapValue[i] = mapValue[i - 2] + mapValue[i - 1];
        }
        return mapValue[n];
    }
};

int main() {

    Solution obj;
    int x = 1;
    // while (x < 10) {
    //     cout << obj.climbStairs(x) << endl;
    //     cout << "sleeping for 1 second" << endl;
    //     sleep(1);
    //     x++;
    // }

    cout << obj.climbStairs(44) << endl;

    return 0;
}
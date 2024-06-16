#include "UTILS/helper.h"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> v1(5, vector<int>(3, 0));
        vector<vector<int>> v1(numRows);
        v1[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            v1[i].push_back(1); // first value
            for (int j = 1; j < i; j++) {
                v1[i].push_back(v1[i - 1][j] + v1[i - 1][j - 1]);
            }
            v1[i].push_back(1); //  last eleemnt
        }
        return v1;
    }

    vector<int> getRow(int rowIndex) {

        // vector<vector<int>> v1(rowIndex+1);

        vector<int> prev;
        vector<int> curr;

        prev.push_back(1);
        // curr.push_back(1);

        // v1[0].push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            curr.push_back(1); // first value
            for (int j = 1; j < i; j++) {
                curr.push_back(prev[j] + prev[j - 1]);
            }
            curr.push_back(1); //  last elemnt

            cout << "Prev : ";
            printVector(prev);
            cout << "Curr : ";
            printVector(curr);

            // copy(curr.begin(), curr.end(), prev.begin());
            // copyVector(curr, prev);
            prev = curr;
            curr = {};
        }
        return prev;
    }
};

int main() {

    Solution s;
    vector<vector<int>> vect = s.generate(4);
    print2DVector(vect);

    vector<int> res = s.getRow(3);
    printVector(res);

    return 0;
}
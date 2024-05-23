#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define uli unsigned long int

/*
 * Complete the 'taumBday' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER b
 *  2. INTEGER w
 *  3. INTEGER bc
 *  4. INTEGER wc
 *  5. INTEGER z
 */

long taumBday(int b, int w, int bc, int wc, int z) {
    // Write your code here
    long int ans;
    if (bc < wc) {
        ans = b * bc + w * wc;
    } else {
        ans = b * wc + w * bc;
    }
    if (ans > z) {
        ans = ans + z;
    }
    return ans;
}

int main() {
    vector<int> a = {1, 1, 2, 2, 4, 4, 5, 5, 5};

    cout << pickingNumbers(a);

    return 0;
}

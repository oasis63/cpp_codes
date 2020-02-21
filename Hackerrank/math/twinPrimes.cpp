#include<bits/stdc++.h>
using namespace std;

/*
    Copied Code
*/

const int MAXN = 1000000 + 100;

int l, r;
bool isPrime[MAXN];

int main() {

    cin >> l >> r;
    assert(1 <= l && l <= r && r <= 1000000000);
    assert(r - l <= 1000000);

    for(int i = 0; i <= r - l; i++)
        isPrime[i] = true;

    for(int i = 2; i * i <= r; i++) {

        int startPos = l / i * i;

        if (startPos < l)
            startPos += i;

        if (startPos == i)
            startPos += i;

        for(int j = startPos; j <= r; j += i)
            isPrime[j - l] = false;
    }

    int ret = 0;

    for(int i = 0 + (l == 1); i <= r - l - 2; i++)
        ret += isPrime[i] & isPrime[i + 2];

    cout << ret << endl;

    return 0;
}
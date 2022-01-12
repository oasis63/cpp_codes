#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<ll>> v(26);

    for (ll i = 0; i < 26; i += 1){
        v[i].resize(n, 0);
    }

    v[s[0] - 'a'][0] = 1;

    for (ll i = 1; i < n; i += 1){
        v[s[i] - 'a'][i] = 1;
    }

    for (ll i = 0; i < 26; i += 1){
        for (ll j = 1; j < n; j += 1){
            v[i][j] += v[i][j - 1];
        }
    }

    ll ans = 0;

    for (ll i = 0; i < n; i += 1){
        for (ll j = i + 1; j < n; j += 1){
            if (s[i] == s[j]){
                for (ll k = 0; k < 26; k += 1){
                    ans += (v[k][n - 1] - v[k][j]) * (v[k][j - 1] - v[k][i]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
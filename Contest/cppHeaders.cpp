#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

const double eps=1E-9;
const double Exp=2.718281828459045;
const double pi=3.14159;
const double E = 2.7182818284590452354;

#define f first
#define s second
#define linf 2000000000000000000LL
#define FILL(a,b) memset(a, b, sizeof(a))
#define pb push_back
#define mp make_pair
#define sc(mas) scanf("%d",&mas)
#define scll(mas) scanf("%lld",&mas)
#define sc2(f1,f2) scanf("%d%d",&f1,&f2)
#define sc3(f1,f2,f3) scanf("%d%d%d",&f1,&f2,&f3)
#define bit(mask,i) ((mask>>i)&1)
#define pri(ff) printf("%d\n",ff)
#define pr2(f1,f2) printf("%d %d\n",f1,f2)
#define prll(fl) printf("%lld\n",fl)
#define prid(f1) printf("%.15lf\n",f1);
#define prn printf("NO\n")
#define pry printf("YES\n")

const int Max_Bit=63;
const int INF=1000000000;
const ll LINF=1000000000000000007ll;
const int MOD=1000000007;
const int NMAX=100005;
const int MMAX=105;
const int base=1000*1000*1000;

int n;

int main() {
    cin >> n;
    int cnt = 1;
    char prev1 = ' ', prev2 = ' ';
    for(int i=0;i<n;i++) {
        char c;
        cin >> c;
        if(prev2 == ' ') prev2 = c;
        else {
            if(c == prev2) continue;
            if(prev1 == ' ') prev1 = c;
            else {
                if(c == prev1) continue;
                if(c != prev1 && c != prev2) {
                    cnt++;
                    prev2 = c;
                    prev1 = ' ';
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
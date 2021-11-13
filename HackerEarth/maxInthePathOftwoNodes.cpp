#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y); }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector< pair<int, int> > VPII;
typedef vector< pair<int, PII > > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;
struct node
{
    struct node *left, *right;
    int data;
}*root;
node *getNode(int x)
{
    node *p = new node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insert(int x)
{
    node *p = root, *q = NULL;
    while(p != NULL)
    {
        q = p;
        if(p->data < x) p = p->right;
        else p = p->left;
    }
    if(q == NULL)
        p = getNode(x);
    else
    {
        if(q->data < x) q->right = getNode(x);
        else q->left = getNode(x);
    }
}
int findMaxInPath(node *q, int x)
{
    node *p = q;
    int mx = -1;
    while(p->data != x)
    {
        if(p->data > x)
        {
            mx = max(mx, p->data);
            p = p->left;
        }
        else
        {
            mx = max(mx, p->data);
            p = p->right;
        }
    }
    return max(mx, x);  
}
int findMax(int x, int y)
{
    node *p = root;
    while((x < p->data and y < p->data) or (x > p->data and y > p->data))
    {
        if(x < p->data and y < p->data)
            p = p->left;
        else if(x > p->data and y > p->data)
            p = p->right;
    }
    return max(findMaxInPath(p, x), findMaxInPath(p, y));
}
int main(int argc, char* argv[])
{
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    int n, a, x, y;
    cin >> n;
    assert(1 <= n and n <= 100000);
    cin >> a;
    assert(1 <= a and a <= INF);
    root = getNode(a);
    REP(i, 1, n, 1)
    {
        cin >> a;
        assert(1 <= a and a <= INF);
        insert(a);
    }
    cin >> x >> y;
    assert(1 <= x and x <= INF);
    assert(1 <= y and y <= INF);
    int ans = findMax(x, y);
    cout << ans << endl;
    return 0;
}
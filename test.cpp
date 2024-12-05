/*
    ॐ नमः शिवाय | 
*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long int
#define uli unsigned long int

// #define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
// #define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define print2DVector(vec) { for (const auto &row : vec) { for (const auto &element : row) cout << element << " "; cout << endl; } }

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


class Solution{
    public:
        int firstUniqChar(string s) {
            cout<<" s : " << s << endl;
            
            int n = s.length();
            unordered_map<char,int> freq;
            
            for( char c : s){
                freq[c]++;
            }
            
            for(int i = 0;i<n;i++){
                if( freq[s[i]] == 1) return i;
            }
            
            return -1;    
        }

        int findKthLargest(vector<int> nums, int k) {
            sort(nums.rbegin(), nums.rend());
            int n = nums.size();
            if( k < n ) return nums[k-1];

            return -1;
        }

        // nums = [1, 2, 3, 4, 5]

        int solve(vector<int> nums) {
            // min-heap
            priority_queue<int, vector<int>, greater<int>> minHeap;
            int n = nums.size();
            int totalCost = 0;

            for(int num : nums){
                minHeap.push(num);
            }

            while(!minHeap.empty()){
                int firstElem = minHeap.top(); minHeap.pop();
                int sum = firstElem;
                if(minHeap.size() > 0 ){
                    int secondElem = minHeap.top(); minHeap.pop();
                    sum += secondElem;
                }
                minHeap.push(sum);
                totalCost += sum;

                if( minHeap.size() == 1){
                    break;
                }
            }
            
            return totalCost;
        }

        int distributeCandies(vector<int> candies) {
            int n = candies.size();
            int temp = n/2;
            set<int> s;
            for(int a : candies){
                s.insert(a);
            }
            
            int ss = s.size();
            
            return ss <= temp ? ss : temp;
        }
};

Solution sol;

int32_t main() {

    #ifndef ONLINE_JUDGE
        freopen("inputs.txt",  "r",  stdin);
        freopen("outputs.txt", "w", stdout);
    #endif


    vector<int> nums {1,1,2,2,3,4};

    int res = sol.distributeCandies(nums);

    bug(res);

    return 0;
}

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
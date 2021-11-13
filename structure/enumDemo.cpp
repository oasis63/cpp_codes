#include <iostream>
    using namespace std;
    int main()
    {
        enum flag {Orange, White, Green};
        // enum color {Orange, Yellow,Red};  // uncomment will give compilation error
        int i = 0;
        for (i = Orange; i <= Green; i++) {
            cout<<i;
        }
        return 0;
    }
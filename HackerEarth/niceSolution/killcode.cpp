#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;

        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        int temp=n,max=INT_MIN;

        for(int i=0;i<n;i++){
            int k=0;

            if(m<a[i]){

                k=a[i]/m;

                if(a[i]%m!=0)
                    k++;

                if(k>=max){
                    max=k;
                    temp=i+1;
                }
            }
        }
        cout << temp << endl;
    }

    return 0;
}

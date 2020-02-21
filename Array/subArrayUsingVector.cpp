#include <bits/stdc++.h>
using namespace std;

int main()
{
        vector<int> array{1,2,3};
    /* ... initialization of array ... */
    vector< vector<int> > subarray;

    for(int start=0; start<array.size(); start++)
    {
        for(int end=start; end<array.size(); end++)
        {
            vector<int> sub;
            for(int i=start; i<=end; i++)
            {
                sub.push_back(array[i]);
            }
            subarray.push_back(sub);
            sub.clear();
        }
    }

    for(int i=0;i<subarray.size();i++){
        for(int j=0;j<subarray[i].size();j++){
            cout<<subarray[i][j]<<" ";
        }
        cout<<endl;
    }



}

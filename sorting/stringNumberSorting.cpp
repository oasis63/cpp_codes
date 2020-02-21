#include <bits/stdc++.h>
using namespace std;

bool compare(string s1,string s2){

    int n1 = s1.length();
    int n2  = s2.length();

    if(n1 < n2)
        return true;
    if(n2 < n1)
        return false;

    //same length
    for(int i=0;i<n1;i++){

        if(s1[i] < s2[i])
            return true;
        if(s1[i] > s2[i])
            return false;

    }

    return false;
}

void bigSorting(vector<string> numStrings) {

    sort(numStrings.begin(),numStrings.end(),compare);

    int n = numStrings.size();

    for(int i=0;i<n;i++){
        cout<<numStrings[i]<<endl;
    }
}

int main(){

    int n;
    cin >> n;

    vector<string> numStrings;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin>>tmp;
        numStrings.push_back(tmp);
    }

    bigSorting(numStrings);

    return 0;
}

/*

6
31415926535897932384626433832795
1
3
10
3
5


*/

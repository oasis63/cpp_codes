#include<bits/stdc++.h>
using namespace std;


 bool isValid(string s) {
    if (s.size() > 1 && s[0]  ==  '0')
        return false;
    if (stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}

vector<string> restoreIpAddresses(string s)  {
    vector<string> ans;
    if (s.size() > 12 || s.size() < 4)
        return ans;

    for (int i = 1; i < 4; i++) {
        string first  =  s.substr(0, i);
        if (!isValid(first))
            continue;
        for (int j = 1; i + j < s.size() && j < 4; j++) {
            string second  =  s.substr(i, j);
            if (!isValid(second))
                continue;
            for (int k = 1; i + j + k < s.size() && k < 4; k++) {
                string third = s.substr(i + j, k);
                string fourth = s.substr(i + j + k);
                if (isValid(third) && isValid(fourth)) {
                    string current  =  first + "." + second + "." + third + "." + fourth;
                    ans.push_back(current);
                }
            }
        }
    }

    return ans;
}
int main(){

//    string str = "25525511135";

    string str = "222134";

    vector<string> validIps = restoreIpAddresses(str);

    cout<<"Valid ips generated from string : "<<str<<endl;

    int n = validIps.size();
    for(int i=0;i<n;i++){
        cout<<validIps[i]<<endl;
    }


    return 0;
}

 #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;

    if(n>10 || n<1){
        cout<<"Invalid Test"<<endl;
        return 0;
    }

    for(int k=0;k<n;k++){
        string s;cin>>s;
        int len=s.length();

        if(len>100 || len<1){
            cout<<"Invalid Input"<<endl;
             continue;
        }


        int lower=0;
        int upper=0;

        if(isalnum(s[0])){

            for(int i=0;i<s.length();i++){
                if(islower(s[i]))
                    lower++;
                else if(isupper(s[i]))
                    upper++;

            }

            if(lower==0 && upper==0){
                cout<<"Invalid Input"<<endl;
                continue;
            }

            int diff = (lower<upper) ? lower : upper;
            cout<<diff<<endl;


        }
        else
            cout<<"Invalid Input"<<endl;
    }
}

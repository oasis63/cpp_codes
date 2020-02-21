#include <iostream>
using namespace std;

int main()
{
    string sub,main,temp;cin>>sub>>main;
    
    int count=0;
    
    int sublen= sub.length();
    int mainlen = main.length();
    
    for(int i=0;i<mainlen-sublen+1;i++){
            temp = main.substr(i,sublen);
            
            if(temp==sub)
                count++;
    }
    
    cout<<count<<endl;
}

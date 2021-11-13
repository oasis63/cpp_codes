#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> vect{1,2,3,4};

    if(find(vect.begin(),vect.end(),4) != vect.end()){
        cout<<"4 is present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }

    if(find(vect.begin(),vect.end(),334) == vect.end()){
        cout<<"absent"<<endl;
    }else{
        cout<<"present"<<endl;
    }

}

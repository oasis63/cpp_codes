#include<bits/stdc++.h>
using namespace std;

// C++ string methods

int main() {

    // raw input initialization
    string str1("First String");

    // initialization by another string
    string str2(str1);

    cout<<"str1 :"<<str1<<endl;
    cout<<"str2:"<<str2<<endl;

    // initialization with number of Characters
    string str3(5,'#');
    cout<<"str3:"<<str3<<endl;

    // from index 2 .. 5 characters copy
    string str4(str1,2,5);
    cout<<"str4:"<<str4<<endl;

    string str5(str1.begin(),str1.begin()+5);
    cout<<"str5:"<<str5<<endl;

    // clear the characters of a string

    /*str5.clear();
    cout<<"str5:"<<str5<<endl;*/

    cout<<str1.at(4)<<" "<<str1[4]<<endl;
    cout<<str1.front()<<" "<<str1.back()<<endl;

    str5.append(" extension ");
    cout<<str5<<endl;

    str5.append(str1,0,8);
    cout<<str5<<endl;

    // search string in another string

    string key = "String";

    if(str1.find(key) != string::npos){
        cout<<key << " is found at index : "<<str1.find(key)<<" in string " << str1<< endl;
    }else{
        cout<<key + " + is not present in string " << str1<< endl;
    }

    string url = "google co in";
    // search starts from the 4th index of the given string
    cout<<url.find("o",4)<<endl; 


    // substrings
    // (index,length of substring)

    cout<<str1.substr(3,5)<<endl;

    // (index) .. till last
    cout<<str1.substr(3)<<endl;

    // deleting characters from a string

    cout<<"str2 before erasing: "<<str2<<endl;

    // (starting_index,number_of_characters)
    str2.erase(4,5);
    cout<<"str2 after erasing : "<<str2<<endl;

    str2.erase(str2.begin()+2,str2.end()-3);
    cout<<str2<<endl;

    string str6 = "This is a examples";
    // (starting_index,num_of_characters)
    str6.replace(2,7,"ese are test");

    cout<<str6<<endl;
}

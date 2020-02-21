#include<bits/stdc++.h>
using namespace std;

string floatingPart(string str){
    int pos = str.find(".");
    if(pos == string::npos)
        return "";
    else
        return str.substr(pos+1);
}

string replaceBlankWith20(string str){

    string replaceBy = "%20";
    int n = 0;

    while((n=str.find(" ",n)) != string::npos){
        str.replace(n,1,replaceBy);
        n += replaceBy.length();
    }


    return str;

}

int main(){

    string fnum = "2334.343";
    cout<<"Floating Part "<<floatingPart(fnum)<<endl;

    string str = "hellozzzzz";
    // (starting_index, number_of_characters_from_the_main_string,replaced_with_string)
    str.replace(2,0,"BBBBBB");
    cout<<str<<endl;
    str.replace(10,5,"END");
    cout<<str<<endl;


    string url = "google co in";
    cout<<url.find("o",4)<<endl;

    cout<<replaceBlankWith20(url)<<endl;
}

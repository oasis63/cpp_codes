#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

    ifstream myFile,netFile;
    myFile.open("testOutput.txt");
    netFile.open("testCorrectOutput.txt");

    ofstream comp;
    comp.open("testCompareResults.txt");

    string m,c;
    int i=1;

    ll countErrors = 0;

    comp<<"output\t"<<"correctOutput\t"<<"line\n"<<endl;

    ll count_outputs = 0;

    while(!myFile.eof() && !netFile.eof()){
        myFile>>m;
        netFile>>c;

        count_outputs++;

        if(m!=c){
            comp<<m<<"\t\t"<<c<<"\t\t"<<i<<endl;
            countErrors++;
        }

        i++;
    }

    comp<<"\n\nNumber of total outputs : "<<count_outputs<<endl;
    comp<<"\n\nNumber of Erros Occurred  :"<<countErrors<<endl;

    return 0;
}

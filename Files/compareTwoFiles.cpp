#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

	ifstream myFile,netFile;
	myFile.open("output.txt");
	netFile.open("correctOutput.txt");

    ofstream comp;
    comp.open("compareResults.txt");

    string m,c;
    int i=1;

	while(!myFile.eof() && !netFile.eof()){
        myFile>>m;
        netFile>>c;

        if(m!=c){
            comp<<m<<"\t"<<c<<"\t"<<i<<endl;
        }

        i++;
	}


	return 0;
}

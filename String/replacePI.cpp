#include <iostream>
#include<string.h>
using namespace std;

/*
Replace pi with 3.14
*/


void replacePi(char *input){
    int len = strlen(input);

    cout<<input<<endl;

    for(int i=0;i<len-1;i++){
        if(!(input[i]=='p' && input[i+1]=='i')){
            continue;
        }

        int j = len+2;
        input[j]='\0';
        j--;
        while(j>i+3){
            input[j] = input[j-2];
            j--;
        }

        input[i] = '3';
        input[i+1] = '.';
        input[i+2] = '1';
        input[i+3] = '4';

        len += 2;
    }

}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

#include<iostream>
using namespace std;


int allIndexes(int *input,int n,int x,int *output){
    static int idx = -1;
    idx++;
    int *temp = output;
    if(n == 0)
        return 0;
    else{
        int k=0;
        if(input[0] == x){
            *temp = idx;
            k=1;
            temp++;
        }
        return allIndexes(input+1,n-1,x,temp)+k;
    }
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];
//    output[0] = 1;

    int size = allIndexes(input, n, x, output);

    cout<<"size : "<<size<<endl;

    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}

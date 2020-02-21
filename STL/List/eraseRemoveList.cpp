#include<bits/stdc++.h>
using namespace std;

void displayList(list<int> myList){

    for(auto itr = myList.begin();itr != myList.end();itr++){
        cout<<*itr<<" ";
    }

    cout<<endl;
}

int main(){

    list<int> numList;

    numList.push_back(3);
    numList.push_back(3);
    numList.push_back(3);
    numList.push_back(2);
    numList.push_back(2);
    numList.push_back(2);

    displayList(numList);

    for(auto itr = numList.begin();itr != numList.end();itr++){
        if (*itr == 3){
            numList.erase(itr);
            break;
        }
    }

    numList.remove(2);   // removes all the 2

    displayList(numList);

}

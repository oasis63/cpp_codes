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
    numList.push_back(2);

    displayList(numList);

    numList.sort();
    displayList(numList);

    numList.reverse();
    displayList(numList);

    numList.remove(3);

    displayList(numList);

}

#include<bits/stdc++.h>
using namespace std;

int main(){

   vector<vector<int>> obstacles{
        {
            5,5
        },
        {
            4,2
        },
        {
            2,3
        }
    };

    int t5 = 5;
    int t3 = 3;

//    string str = t5+''+t3;

    map<pair<int,int>,bool> myPairMap;
    myPairMap.insert(make_pair(make_pair(4,3),true));
    cout<<"pair map : " << myPairMap[make_pair(42,3)]<<endl;

    pair<int,int> p1 = {4,53};
    cout<<"pair  " << p1.first <<"   "<< p1.second<<endl;


    map<int,bool> numMap;
    numMap.insert(make_pair(4,true));
    numMap.insert(make_pair(24,true));
    numMap.insert(make_pair(114,true));


    cout<<"map values " << numMap[422]<<endl;


//    cout<<str<<endl;

    set<pair<int,int>> myPairSet;

//    myPairSet.insert()

    set<int> mySet;
    mySet.insert(343);
    mySet.insert(3);
    mySet.insert(43);

    set<int>::iterator myiterator = mySet.begin();

    while(myiterator != mySet.end()){
        cout<<*myiterator<<endl;
        myiterator++;
    }

    auto search = mySet.find(3);

    if(search != mySet.end()) {
        cout << "Found " << *search << '\n';
    }
    else {
        cout << "Not found\n";
    }



}

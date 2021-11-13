#include<iostream>
#include<list>
using namespace std;

void showList(list<int> list1){

    for(auto x : list1){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    list<int> list1 = {1,1,1,1,1,2,2,2,2,2,4,4,4,5,5,3,3,3,3};
    list<int> list2 = {2,4,6};

    cout<<"list1 before unique operation :"<<endl;
    showList(list1);

    list1.unique();
    //list1.sort();
    cout<<"list1 after unique operation :"<<endl;
    showList(list1);

    list<int>::iterator itr = list1.begin();
    advance(itr,3);
    cout<<"itr points to :"<<*itr<<endl;

    cout<<"list2 elements :"<<endl;
    showList(list2);

    list1.splice(itr,list2);
    cout<<"list1 after splice operation :"<<endl;
    showList(list1);

}

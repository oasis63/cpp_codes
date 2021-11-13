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

    list<int> list1;
	list<int>:: iterator itr = list1.begin();

    // emplace_back(i) is faster than push_back(i)
    for(int i=1;i<=5;i++){
        list1.emplace_back(i*i);
    }
    cout << "List after emplace_back operation is : "<<endl;
    showList(list1);


    list1.emplace_front(1000);
    cout << "List after emplace_front operation is : "<<endl;
    showList(list1);

    list1.emplace_back(1999);
    cout << "List after emplace_back operation is : "<<endl;
    showList(list1);

    advance(itr,2);
    list1.emplace(itr,555);
    cout << "List after emplace operation at second place is : "<<endl;
    showList(list1);

    // bringing back the itr to start of the list
    itr = list1.begin();

    // advancing the list iterator
    advance(itr,-2);
    list1.emplace(itr,999);
    cout <<"List after inserting element at second last position "<<endl;
    showList(list1);

}

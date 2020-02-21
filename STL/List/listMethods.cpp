#include<bits/stdc++.h>
using namespace std;

void printList(list<int> li){
    list<int>::iterator itr = li.begin();

    while(itr!=li.end()){
        cout<<*itr<<" ";
        itr++;
    }
    cout<<endl;
}

int main(){
    list<int> li {6,3,1,4,6,2,1,5};

    list<int>::iterator itr = li.begin();

    printList(li);

    li.push_back(43);

    printList(li);

    li.push_front(343);

    printList(li);

    // sorting the list

    li.sort();

    printList(li);

    li.pop_front();

    printList(li);

    li.pop_back();

    li.remove(1);  // deletes the first element

    printList(li);

    cout<<li.front()<<endl;
    cout<<li.back()<<endl;

     cout<<"\nNumber of elements : " <<li.size()<<endl;

    li.clear();
    cout<<"\nAll the elements are element"<<endl;
    printList(li);



}

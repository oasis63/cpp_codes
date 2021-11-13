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

    list<int> list1 = {1,2,3};
    list<int> list2 = {3,2432,23};

    list1.merge(list2);
    cout<<"list1 after merge operation : "<<endl;
    showList(list1);

    // if sorted list after merging .. remains sorted

    list<int> list3 = {1,20,30};
    list<int> list4 = {3,24,54};

    list3.merge(list4);
    cout<<"list3 remains sorted after merge operation : "<<endl;
    showList(list3);


    list<int> nums = {1,2,3,4,5,6,7,8,10};
    cout<<"nums list :"<<endl;
    showList(nums);

    nums.remove_if([](int x){
                   return x%2==0;
                   });

    cout<<"nums list after removing even numbers "<<endl;
    showList(nums);




}

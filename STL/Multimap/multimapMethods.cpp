#include<bits/stdc++.h>
using namespace std;

// Multimap demo

void dispMultimap(multimap<int,int> mmap){
    for(pair<int,int> p : mmap){
        cout<<p.first<<" "<<p.second<<endl;
    }
}

int main(){

    multimap<int,int> mp;

    mp.insert({2,30});
   	mp.insert({ 1, 40 });
	mp.insert({ 2, 60 });
	mp.insert({ 3, 20 });
  	mp.insert(make_pair(3,23));
	mp.insert({ 1, 50 });
	mp.insert({ 4, 50 });
	mp.insert({ 4, 60 });

    dispMultimap(mp);

    cout<<"\nElements from key  3  "<<endl;
    cout<<"KEY\tELEMENT"<<endl;

    for(auto itr = mp.find(3);itr!=mp.end();itr++){
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }


    // function to erase given keys
//    mp.erase(1);
    mp.erase(3);


    auto i = mp.begin();
    advance(i,2);
    mp.erase(i);

    i = mp.find(4);
    mp.erase(i);

    // prints the elements
    cout << "\nThe multimap after applying erase(3) is : \n";
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first<< '\t' << itr->second << '\n';
    }

}

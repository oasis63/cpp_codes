#include<bits/stdc++.h>
using namespace std;

// Multimap demo

void dispMultimap(multimap<int,int> mmap){
    for(pair<int,int> p : mmap){
        cout<<p.first<<" "<<p.second<<endl;
    }
}

int main(){


    multimap<int,int> mmap;

    mmap.insert(pair<int,int>(1,40));
    mmap.insert(pair<int,int>(1,20));
    mmap.insert(pair<int,int>(2,10));
    mmap.insert(pair<int,int>(2,40));
    mmap.insert(pair<int,int>(2,433));
    mmap.insert(make_pair(3,923));
    mmap.insert(make_pair(3,223));
    mmap.insert(make_pair(4,123));
    mmap.insert(make_pair(4,100));
    mmap.insert(make_pair(4,2343));
    mmap.insert(make_pair(5,23));
    mmap.insert(make_pair(5,23));
    mmap.insert(make_pair(6,444));
    mmap.insert(make_pair(6,23));

    dispMultimap(mmap);

    // copying the elements to a new multmap
    multimap<int,int> mmap2(mmap.begin(),mmap.end());

    cout<<"Copied Multimap2 :"<<endl;
    dispMultimap(mmap2);

    cout<<"multimap2 after removing keys <4 :"<<endl;
    mmap2.erase(mmap2.begin(),mmap2.find(4));
    dispMultimap(mmap2);

    cout<<"Removing elements with key = 4 "<<endl;
    mmap2.erase(4);
    dispMultimap(mmap2);


    cout<<"\nBounds of value for a key\n"<<endl;
    cout<<"mmap.lower_bound(4) : "<<"\tKEY = ";
    cout<<mmap.lower_bound(4)->first<<"\t";
    cout<<"\tVALUE :"<<mmap.lower_bound(4)->second<<endl;

    cout<<"mmap.upper_bound(4) : "<<"\tKEY = ";
    cout<<mmap.upper_bound(4)->first<<"\t";
    cout<<"\tVALUE :"<<mmap.upper_bound(4)->second<<endl;


}

// CPP program to illustrate the
// list::resize() function
#include <bits/stdc++.h>
using namespace std;

void showList(list<int> list1){
	for(int x : list1){
		cout<<x<<" ";
	}
	cout<<endl;
}

int main()
{
	// Creating a list
	list<int> demoList;

	// Adding elements to the list
	demoList.push_back(10);
	demoList.push_back(20);
	demoList.push_back(30);
	demoList.push_back(40);

	// Initial list:
	cout << "Initial List: ";
	showList(demoList);

	// Resize list to contain less elements
	demoList.resize(2);
	cout << "\n\nList after first resize: ";
	showList(demoList);

	// Resize list to contain more elements
	demoList.resize(4);
	cout << "\n\nList after second resize: ";
	showList(demoList);
	// resize list to contain more elements
	// with a specified value
	demoList.resize(10, 50);
	cout << "\n\nList after third resize: ";
	showList(demoList);

	return 0;
}

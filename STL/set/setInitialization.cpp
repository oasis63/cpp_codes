// C++ program to demonstrate that we can use auto to 
// save time when creating iterators 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// Create a set of strings 
	set<string> st({ "geeks", "for", "geeks", "org" }); 

	// 'it' evaluates to iterator to set of string 
	// type automatically 
	for (auto it = st.begin(); it != st.end(); it++) 
		cout << *it << " "; 

	return 0; 
} 

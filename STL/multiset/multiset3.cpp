#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
	
	multiset<string> st;

	st.insert("1");
	st.insert("1");
	st.insert("3");
	st.insert("4");
	st.insert("10");
	st.insert("12");
	st.insert("10");
	st.insert("11");

	set<string>::iterator it = st.begin();
	while(it!=st.end()){
		cout<<*it<<endl;
		it++;
	}

	return 0;
}
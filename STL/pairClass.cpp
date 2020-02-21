//pair tempelate class
#include<iostream>
using namespace std;

class Student
{
private:
	string name;
	int marks;
public:
	void setStudent(string s ,int m)
	{
		name = s;
		marks = m;
	}

	void showStudent()
	{
		cout<<"Name :"<<name<<". ";
		cout<<"Marks :"<<marks<<endl;
	}



};
 
int main()
{
	pair <string,int> p1;
	pair <int,float> p2;
	pair <int,Student> p3;

	Student s1;
	s1.setStudent("manish",406);

	p1=make_pair("rajesh",4);
	p2=make_pair(43,53.532);
	p3=make_pair(43,s1);

	cout<<"First pair :";
	cout<<p1.first<<" "<<p1.second<<endl;

	cout<<"Second pair :";
	cout<<p2.first<<" "<<p2.second<<endl;

	cout<<"Third pair :";
	cout<<p3.first<<" ";
	(p3.second).showStudent();

}
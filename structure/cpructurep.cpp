//Use of structure
#include<iostream>
using namespace std;
struct test
{
  int get()
  {
    return x;
  }
  void put(int i)
  {
    x=i;
  }
  private:
    int x;
};
int main()
{
  test s;
  s.put(15);
  cout<<s.get()<<endl;

 return 0;
}

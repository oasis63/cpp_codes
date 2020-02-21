//Use of structure
#include<iostream>
using namespace std;
struct test
{
  private:
    int x;
    
  int get()
  {
    return x;
  }
  void put(int i)
  {
    x=i;
  }
};
int main()
{
  test s;
  s.put(15);
  cout<<s.get()<<endl;

 return 0;
}

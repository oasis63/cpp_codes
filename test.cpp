#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

class Solution{
    public:
        void arrange(vector<int> &A);
};

void printVector(vector<int> vect){
    int n = vect.size();
    for(int i=0;i<n;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

void Solution::arrange(vector<int> &A) {
   int n = A.size();

    // using extra space 
   vector<int> tempVect(n);
   printVector(tempVect);

   for(int i=0;i<n;i++){
       tempVect[A[i]]=i;
   }    

    cout<<"Answer vector"<<endl;
    printVector(tempVect);

}

int main(){

    Solution s;

    // vector<int> vect{1,0};
    vector<int> vect{0,2,4,1,3};   // 0 4 3 2 1  
    // vector<int> vect{ 4, 0, 2, 1, 3};


    cout<<vect.size()<<endl;

    string str = "fsdlfjasjf";


    cout<<"string size : ";
    cout<<str.length()<<endl;



    s.arrange(vect);


    


    

    vect.size();

    // printVector(vect);    

    return 0;
}
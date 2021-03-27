#include<bits/stdc++.h>
using namespace std;

void segragate012(int);

void segragate012(int a[], int n)
{
    int low = 0, high = n-1, mid = 0;

    while(mid <= high){

        if(a[mid]==0)
            swap(a[mid++], a[low++]);
       
        else if(a[mid]==1)
             mid++;

        else
            swap(a[mid], a[high--]);
    }

    
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        segragate012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }

<<<<<<< Updated upstream
=======
    if(root->right){
        retRight = hasPathSum(root->right,sum-root->value,vect,ans);
    }

    /*if(retLeft || retRight){
        ans.push_back(vect);
        vect.clear();
    }*/

    return retLeft || retRight;
}

int main(){


    Node* root=new Node(5);
    root->left= new Node(4);
    root->right = new Node(8);
    root->left->left=new Node(11);
    root->left->left->left=new Node(7);
    root->left->left->right=new Node(2);
    root->right->left=new Node(13);
    root->right->right=new Node(4);
    root->right->right->right=new Node(1);


//    zigzag(root);


    int sum = 22;

	vector<vector<int>> ans;

    vector<int> vect;

    cout<<hasPathSum(root,sum,vect,ans)<<endl;

	for(int i=0;i<ans.size();i++){
		for(int j =0;j<ans[i].size();j++){
			cout<<ans[i][j]<<"  ";
		}
		cout<<endl;
	}

    cout<<"I am writting this in test branch for testing purpose. "<<endl;

    return 0;

>>>>>>> Stashed changes
}

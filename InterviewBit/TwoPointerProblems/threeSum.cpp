#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	
	vector<vector<int>> ans;
	sort(nums.begin(),nums.end());

	int n = nums.size();

	for(int i=0;i<n-2;i++){
		// cout<<"hello1"<<endl;
		
		// skip all the duplicate triplets 
		if(i > 0 && nums[i] == nums[i-1])
			continue;

		int j = i + 1;
		int k = n - 1;


		while(j<k){
			// cout<<"hello2"<<endl;
			int sum = nums[i] + nums[j] + nums[k];

			if(sum == 0){
				vector<int> triplet;
				triplet.push_back(nums[i]);
				triplet.push_back(nums[j]);
				triplet.push_back(nums[k]);
				ans.push_back(triplet);

				// skip all the duplicates 
				j++;
				while(j<k && nums[j] == nums[j-1])
					j++;

			}

			if(sum >  0){
				k--;
			}else if(sum < 0){
				j++;
			}

		}

	}




	return ans;
        
}

int main(){
	
	vector<int> nums{-1, 0, 1, 2, -1, -4};

	vector<vector<int>> ans = threeSum(nums);

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}
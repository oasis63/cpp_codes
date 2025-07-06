class Solution {
  public:
    void solve(vector<vector<int>> &ans, vector<int> &vect, int currSum,
               int targetSum, TreeNode *root) {
        if (root->left == NULL && root->right == NULL && currSum == targetSum) {
            ans.push_back(vect);
            return;
        }
        bool leftPush = false, rightPush = false;
        ;
        int key;
        if (root->left) {
            key = root->left->val;
            vect.push_back(key);
            leftPush = true;
            solve(ans, vect, currSum + key, targetSum, root->left);
        }
        if (leftPush)
            vect.pop_back();

        if (root->right) {
            key = root->right->val;
            vect.push_back(key);
            rightPush = true;
            solve(ans, vect, currSum + key, targetSum, root->right);
        }
        if (rightPush)
            vect.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> vect;
        vector<vector<int>> ans;

        if (!root)
            return ans;

        vect.push_back(root->val);

        int currSum = root->val;

        solve(ans, vect, currSum, targetSum, root);

        return ans;
    }
};
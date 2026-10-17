/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int> &temp,int currsum){
        if(root==NULL) return;
        currsum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(currsum==targetSum){
                ans.push_back(temp);
            }
        }
        else{
            solve(root->left,targetSum,ans,temp,currsum);
            solve(root->right,targetSum,ans,temp,currsum);
        }
        // currsum-=root->val;
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(root,targetSum,ans,temp,sum);
        return ans;
    }
};
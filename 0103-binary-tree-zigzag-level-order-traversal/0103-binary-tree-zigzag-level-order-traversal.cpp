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

    void solve(TreeNode* root,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        int l=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(l%2==0){
                    ans.push_back(level);
                }
                else{
                    reverse(level.begin(),level.end());
                    ans.push_back(level);
                }
                l++;
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                level.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        solve(root,ans);
        return ans;
    }
};
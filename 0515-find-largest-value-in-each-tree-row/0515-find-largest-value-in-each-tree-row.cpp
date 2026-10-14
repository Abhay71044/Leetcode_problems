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

    void solve(TreeNode* root,vector<int>&ans){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                int maxi=INT_MIN;
                for(int i=0;i<level.size();i++){
                    maxi=max(maxi,level[i]);
                }
                ans.push_back(maxi);
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

    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        solve(root,ans);
        return ans;
    }
};
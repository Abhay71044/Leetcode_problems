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

    void solve(TreeNode* root,int &ans){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                ans=sum;
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=temp->val;;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }

    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
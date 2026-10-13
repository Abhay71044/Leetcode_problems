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

    void solve(TreeNode* root,int& maxi,int& anslevel){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int level=1;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if (sum > maxi) {
                    maxi = sum;
                    anslevel = level;
                }
                sum = 0;
                level++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }

    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maxi=INT_MIN;
        int anslevel=1;
        solve(root,maxi,anslevel);
        return anslevel;
    }
};
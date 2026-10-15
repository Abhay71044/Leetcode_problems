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

    bool solve(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>level;
        int height=0;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                if(height % 2 == 0){
                    for(int i=0;i<level.size();i++){
                        if(level[i] % 2 == 0){
                            return false;
                        }
                        if(i+1 < level.size() && level[i] >= level[i+1]){
                            return false;
                        }
                    }
                }
                else{
                    for(int i=0;i<level.size();i++){
                        if(level[i] % 2 == 1){
                            return false;
                        }
                        if(i+1 < level.size() && level[i] <= level[i+1]){
                            return false;
                        }
                    }
                }
                level.clear();
                height++;
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
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        bool result=solve(root);
        return result;
    }
};
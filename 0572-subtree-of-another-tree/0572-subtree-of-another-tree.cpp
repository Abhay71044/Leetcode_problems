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

    bool sametree(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
        if(left->val!=right->val) return false;
        bool leftans=sametree(left->left,right->left);
        bool rightans=sametree(left->right,right->right);
        return leftans && rightans;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if (sametree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
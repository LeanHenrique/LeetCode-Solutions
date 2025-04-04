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
    int Maxdeeper(TreeNode* root){
        if(!root) return 0;
        return 1 + max(Maxdeeper(root->left), Maxdeeper(root->right));
    }

    TreeNode* findsmallestsubtree(TreeNode* root, int Currentdeep, int maxdeep){
        if(!root || Currentdeep == maxdeep) return root;

        TreeNode* left = findsmallestsubtree(root->left,Currentdeep + 1, maxdeep);
        TreeNode* right = findsmallestsubtree(root->right,Currentdeep + 1, maxdeep);

        if(left && right) return root;
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxdeep = Maxdeeper(root);
        return findsmallestsubtree(root, 1, maxdeep);    
    }
};

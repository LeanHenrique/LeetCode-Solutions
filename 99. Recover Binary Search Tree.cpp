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
    void recoverTree(TreeNode* root) {
        vector<int> tree;
        pair<int, int> elements;

        inOrder(root, tree);

        elements = verifyElement(tree);

        recover(root, elements.first, elements.second);
        
    }

    void inOrder(TreeNode* root , vector<int>& tree) {
        if(root == nullptr) return;


        inOrder(root -> left, tree);

        tree.push_back(root->val);

        inOrder(root -> right, tree);
    }

    pair<int,int> verifyElement(vector<int>& tree){
        int x = 0, y = 0;
        bool firstOcurrency = false;
        for(int i = 0; i < tree.size() - 1; i++){
            if(tree[i] > tree[i+1]){
                y = tree[i+1];
                if(!firstOcurrency){
                    x = tree[i];
                    firstOcurrency = true;
                }else{
                    break;
                }
            }
        }
        return {x, y};
    }

    void recover(TreeNode* root, int x, int y){
        if(root == nullptr) return;

        if(root ->val == x)root->val = y;
        else if(root->val == y)root->val = x;

        recover(root->left, x, y);

        recover(root->right, x, y);
    }    
};

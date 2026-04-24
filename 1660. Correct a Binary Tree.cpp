class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<int> visited;
        return travess(root, visited);
    }

    TreeNode* travess(TreeNode* root, unordered_set<int>& visited) {
        if (root == nullptr) return nullptr;

        if (root->right && visited.count(root->right->val)) {
            return nullptr; 
        }

        visited.insert(root->val);

        root->right = travess(root->right, visited);
        root->left = travess(root->left, visited);

        return root;
    }
};

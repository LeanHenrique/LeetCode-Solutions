class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    TreeNode* findDeepestLCA(TreeNode* root, int targetDepth, int currentDepth) {
        if (!root) return nullptr;
        if (currentDepth == targetDepth) return root;

        TreeNode* left = findDeepestLCA(root->left, targetDepth, currentDepth + 1);
        TreeNode* right = findDeepestLCA(root->right, targetDepth, currentDepth + 1);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = maxDepth(root);
        return findDeepestLCA(root, depth, 1);
    }

    
};

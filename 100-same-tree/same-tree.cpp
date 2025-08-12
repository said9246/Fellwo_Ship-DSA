class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are null → same
        if (!p && !q) return true;

        // One is null, other is not → not same
        if (!p || !q) return false;

        // Values differ → not same
        if (p->val != q->val) return false;

        // Recursively check left and right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

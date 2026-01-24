class Solution {
public:
    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;

        path.push_back(node->val);

        // Leaf node
        if (!node->left && !node->right && targetSum == node->val) {
            res.push_back(path);
        } else {
            dfs(node->left, targetSum - node->val, path, res);
            dfs(node->right, targetSum - node->val, path, res);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }
};

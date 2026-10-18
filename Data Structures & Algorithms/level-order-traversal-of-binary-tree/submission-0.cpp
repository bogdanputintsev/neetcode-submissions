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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result, 0);

        return result;
    }

    void traverse(TreeNode* root, vector<vector<int>>& result, int depth) {
        if (!root) {
            return;
        }

        if (depth >= result.size()) {
            result.push_back({});
        } 
        
        result.at(depth).push_back(root->val);
        
        traverse(root->left, result, depth + 1);
        traverse(root->right, result, depth + 1);
    }
};

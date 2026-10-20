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
    int kthSmallest(TreeNode* root, int k) {
        std::optional<int> result;
        traverse(root, result, k);

        return result.value_or(-1);
    }

    void traverse(TreeNode* root, std::optional<int>& result, int& k) {
        if (!root || result.has_value()) {
            return;
        }

        if (root->left) {
            traverse(root->left, result, k);
        }

        if (result.has_value()) {
            return;
        }

        k--;
        if (k == 0) {
            result = root->val;
            return;
        }

        if (root->right) {
            traverse(root->right, result, k);
        }
    }
};

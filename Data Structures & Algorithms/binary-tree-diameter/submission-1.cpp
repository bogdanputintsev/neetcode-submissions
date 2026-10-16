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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        const auto&[maxStepsFromRoot, maxStepsAcrossChildren] = maxResults(root);

        return max(maxStepsFromRoot, maxStepsAcrossChildren) - 1;
    }

    pair<int, int> maxResults(TreeNode* parent) {
        if (!parent) {
            return {0, 0};
        }

        auto left = maxResults(parent->left);
        auto right = maxResults(parent->right);

        const int maxStepsFromRoot 
            = 1 + max(left.first, right.first);

        const int maxStepsAcrossChildren 
            = max(max(left.second, right.second), (left.first + right.first + 1));

        return { maxStepsFromRoot, maxStepsAcrossChildren };
    }
};
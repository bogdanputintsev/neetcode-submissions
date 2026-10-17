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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        auto leftHeight = height(root->left);
        auto rightHeight = height(root->right);
        if (!leftHeight.second || !rightHeight.second) {
            return false;
        }

        bool balanced = abs(leftHeight.first - rightHeight.first) <= 1;

        return balanced;
    }

    pair<int, bool> height(TreeNode* node) {
        if (!node) {
            return { 0, true };
        }

        auto leftHeight = height(node->left);
        auto rightHeight = height(node->right);
        auto maxHeight = 1 + max(leftHeight.first, rightHeight.first);
        if (!leftHeight.second || !rightHeight.second) {
            return { maxHeight, false };
        }

        auto balanced = abs(leftHeight.first - rightHeight.first) <= 1;
        return { maxHeight, balanced };
    }
};

//     1
//   2   2
//  3      3 
// 4         4

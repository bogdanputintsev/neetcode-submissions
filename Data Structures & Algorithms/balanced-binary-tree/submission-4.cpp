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

        return calculateHeight(root).balanced;
    }

private:
    struct HeightResult {
        int height;
        bool balanced;
    };

    HeightResult calculateHeight(TreeNode* node) {
        if (!node) {
            return { .height = 0, .balanced = true };
        }

        auto left = calculateHeight(node->left);
        auto right = calculateHeight(node->right);
    
        auto maxHeight = 1 + max(left.height, right.height);
        bool balanced = left.balanced && right.balanced 
            && abs(left.height - right.height) <= 1;

        return { maxHeight, balanced };
    }
};


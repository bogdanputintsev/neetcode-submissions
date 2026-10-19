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
    int goodNodes(TreeNode* root) {
        int result = 0;
        captureGoodNodes(root, result);

        return result;
    }

    void captureGoodNodes(TreeNode* node, int& result, int maxValueOnPath = std::numeric_limits<int>::min()) {
        if (!node) {
            return;
        }

        if (node->val >= maxValueOnPath) {
            result++;
            maxValueOnPath = node->val;
        }
        
        captureGoodNodes(node->left, result, maxValueOnPath);
        captureGoodNodes(node->right, result, maxValueOnPath);
    }
};
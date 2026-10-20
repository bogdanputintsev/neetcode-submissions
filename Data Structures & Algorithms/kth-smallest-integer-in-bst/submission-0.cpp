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
        vector<int> allValues;
        traverse(root, allValues);

        return allValues[k - 1];
    }

    void traverse(TreeNode* root, vector<int>& allValues) {
        if (!root) {
            return;
        }

        if (root->left) {
            traverse(root->left, allValues);
        }
        allValues.push_back(root->val);
        if (root->right) {
            traverse(root->right, allValues);
        }

    }
};

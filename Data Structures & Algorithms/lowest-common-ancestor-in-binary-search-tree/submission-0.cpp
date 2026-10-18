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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return nullptr;
        }

        const auto maxVal = max(p->val, q->val);
        const auto minVal = min(p->val, q->val);

        if (root->val > maxVal) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < minVal) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

// 1 

// 1
//   2

//   1
// 2   3


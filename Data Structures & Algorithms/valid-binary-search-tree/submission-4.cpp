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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

    bool isValidBST(TreeNode* root, int localMin, int localMax) {
        if (!root) {
            return true;
        }

        if (root->left) {
            if (root->left->val <= localMin || root->left->val >= localMax) {
                return false;
            }
            if (root->val <= root->left->val) {
                return false;
            }
        }

        if (root->right) {
            if (root->right->val <= localMin || root->right->val >= localMax) {
                return false;
            }
            if (root->val >= root->right->val) {
                return false;
            }
        }

        return isValidBST(root->left, localMin, std::min(root->val, localMax)) 
            && isValidBST(root->right, std::max(root->val, localMin), localMax);
    }
};

//   1
// #   1
// 1: (-inf, inf)
// 

//   1
// 2   3
// 2: (-inf, inf)
// 1: (-inf, 2)
// 3: (2, inf)

//     5
//  4    6
//      3 7

// 5: (-inf, inf)
// 4: (-inf, 5)
// 6: (5, inf)
// 7: (5, 7)
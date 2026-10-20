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
        return isValidBST(root, MINUS_INFINITE, PLUS_INFINITE);
    }

private:

    bool isValidBST(TreeNode* root, int localMin, int localMax) {
        if (!root) {
            return true;
        }

        if (root->left) {

            if (root->val <= root->left->val) {
                return false;
            }
            if (!isInRange(root->left->val, localMin, localMax)) {
                return false;
            }

        }

        if (root->right) {
           
            if (root->val >= root->right->val) {
                return false;
            }
            if (!isInRange(root->right->val, localMin, localMax)) {
                return false;
            }

        }

        return isValidBST(root->left, localMin, std::min(root->val, localMax)) 
            && isValidBST(root->right, std::max(root->val, localMin), localMax);
    }

    static bool isInRange(int value, int minValue, int maxValue) noexcept {
        return minValue < value && value < maxValue;
    }

    static constexpr int MINUS_INFINITE = std::numeric_limits<int>::min();
    static constexpr int PLUS_INFINITE = std::numeric_limits<int>::max();

};


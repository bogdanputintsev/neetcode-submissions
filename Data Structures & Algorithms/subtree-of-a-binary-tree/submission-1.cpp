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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // 1. Hash root tree including its all subtrees.
        hashTree(root);

        // 2. Calculate target hash of what we're looking for
        size_t targetHash = hashTree(subRoot);

        return findByHash(root, targetHash);
    }

private:
    unordered_map<TreeNode*, size_t> hashes;

    size_t hashTree(TreeNode* root) {
        if (!root) {
            return 1235647;
        }

        size_t leftHash = hashTree(root->left);
        size_t rightHash = hashTree(root->right);

        size_t finalHash = root->val;
        finalHash = combineHash(finalHash, leftHash);
        finalHash = combineHash(finalHash, rightHash);

        hashes[root] = finalHash;

        return finalHash;
    }

    size_t combineHash(size_t a, size_t b) {
        return a * 31 + b;
    }

    bool findByHash(TreeNode* root, size_t targetHash) {
        if (!root) {
            return false;
        }

        return hashes[root] == targetHash 
            || findByHash(root->left, targetHash)
            || findByHash(root->right, targetHash);
    }
};
// 3
// 4 5 
// 1 2 X X
// X X 0
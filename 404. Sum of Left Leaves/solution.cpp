// Link: https://leetcode.com/problems/sum-of-left-leaves/

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
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
    void traverse(TreeNode* root, int& sum) {
        if (root->left != nullptr) {
            if (root->left->left == nullptr && root->left->right == nullptr)
                sum += root->left->val;
            traverse(root->left, sum);
        }
        if (root->right != nullptr) {
            traverse(root->right, sum);
        }
    }
};
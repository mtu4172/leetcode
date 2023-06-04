// Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

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
#include <vector>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return v;
    }

    void traverse(TreeNode* root, vector<int>& v) {
        if (!root)
            return;
        if (root->left != nullptr) {
            traverse(root->left, v);
        }
        v.push_back(root->val);
        if (root->right != nullptr) {
            traverse(root->right, v);
        }
    }
};
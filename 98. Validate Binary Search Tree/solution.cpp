// Link: https://leetcode.com/problems/validate-binary-search-tree/

#include <vector>
using namespace std;
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
    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        for (int i = 1; i < vals.size(); i++) {
            if (vals.at(i) <= vals.at(i-1))
                return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& vals) {
        if (root->left != nullptr)
            inorder(root->left, vals);
        vals.push_back(root->val);
        if (root->right != nullptr)
            inorder(root->right, vals);
    }
};
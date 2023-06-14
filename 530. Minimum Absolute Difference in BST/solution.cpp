// Link : https://leetcode.com/problems/minimum-absolute-difference-in-bst/

#include <vector>
#include <cmath>
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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        int min = INT_MAX;
        inorder(root, vals, min);
        return min;
    }
    void inorder(TreeNode* root, vector<int>& vals, int& min) {
        if (root->left != nullptr)
            inorder(root->left, vals, min);
        if (vals.size() > 0 && abs(vals.back() - root->val) < min)
            min = abs(vals.back() - root->val);
        vals.push_back(root->val);
        if (root->right != nullptr) 
            inorder(root->right, vals, min);
    }
};
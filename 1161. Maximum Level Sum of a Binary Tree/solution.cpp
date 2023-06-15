// Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <unordered_map>
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
    int maxLevelSum(TreeNode* root) {
        unordered_map<int, int> sums;
        traverse(root, 0, sums);
        int max = INT_MIN;
        int maxlevel = -1;
        for (auto iter : sums) {
            if (iter.second >= max) {
                max = iter.second;
                maxlevel = iter.first;
            }
        }
        return maxlevel+1;
    }
    void traverse(TreeNode* root, int level, unordered_map<int, int>& sums) {
        if (sums.count(level) == 0)
            sums[level] = root->val;
        else 
            sums[level] += root->val;
        if (root->left != nullptr)
            traverse(root->left, level+1, sums);
        if (root->right != nullptr) 
            traverse (root->right, level+1, sums);
    }

};
# Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    count = 0
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.good(root, root.val)
        

    def good(self, root, mx):
        if root.val >= mx:
            mx = root.val
            self.count += 1
        if root.left:
            self.good(root.left, mx)
        if root.right:
            self.good(root.right, mx)
        return self.count


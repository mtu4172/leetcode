# Link : https://leetcode.com/problems/leaf-similar-trees/?envType=study-plan-v2&envId=leetcode-75

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        list1 = []
        list2 = []
        return self.traverse(root1, list1) == self.traverse(root2, list2)

    def traverse(self, root, list):
        if not root.left and not root.right:
            list.append(root.val)
        if root.left:
            self.traverse(root.left, list)
        if root.right:
            self.traverse(root.right, list)
        return list

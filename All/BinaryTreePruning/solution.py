# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recursivePruning(self, root, parentRoot=None):
        if root:
            if root.left:
                # If root.left is a leaf node and root.left.val = 0 then remove that node.
                if root.left.left is None and root.left.right is None:
                    if root.left.val == 0:
                        root.left = None
                else:
                    self.recursivePruning(root.left, root)
            if root.right:
                # If root.right is a leaf node and root.right.val = 0 then remove that node.
                if root.right.left is None and root.right.right is None:
                    if root.right.val == 0:
                        root.right = None
                else:
                    self.recursivePruning(root.right, root)
            # If root became the leaf node then go again to its parent.
            if root.left is None and root.right is None:
                self.recursivePruning(parentRoot)
        return root

    def pruneTree(self, root: TreeNode) -> TreeNode:
        root = self.recursivePruning(root)
        if root.left is None and root.right is None and root.val == 0:
            return None
        else:
            return root

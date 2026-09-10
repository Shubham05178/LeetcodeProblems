# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.count=0
        def dfs(root):
            if not root:
                return(0,0)
            left_c,left_s=dfs(root.left)
            right_c,right_s=dfs(root.right)
            curr_s=left_s+right_s+root.val
            curr_c=left_c+right_c+1
            if root.val==curr_s//curr_c:
                self.count+=1
            return(curr_c,curr_s)
        dfs(root)
        return self.count
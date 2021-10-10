# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        levelOrderNodes = {}
        level = 0
        queue = [[level, root]]
        while len(queue) > 0:
            level = queue[0][0]
            if level in levelOrderNodes:
                thisLevelItems = levelOrderNodes[level]
                thisLevelItems.append(queue[0][1].val)
                levelOrderNodes[level] = thisLevelItems
            else:
                levelOrderNodes[level] = [queue[0][1].val]
            level += 1
            node = queue.pop(0)[1]
            if node.left is not None:
                queue.append([level, node.left])
            if node.right is not None:
                queue.append([level, node.right])
        return levelOrderNodes.values()

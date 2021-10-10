# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root:
            levelNodes = {}
            queue = [[0, root]]
            while queue:
                currentLevel = queue[0][0]
                currentNode = queue[0][1]
                if currentLevel in levelNodes:
                    currentLevelNodes = levelNodes[currentLevel]
                    currentLevelNodes.append(currentNode.val)
                    levelNodes[currentLevel] = currentLevelNodes
                else:
                    levelNodes[currentLevel] = [currentNode.val]
                queue.pop(0)
                currentLevel += 1
                if currentNode.left is not None:
                    queue.append([currentLevel, currentNode.left])
                if currentNode.right is not None:
                    queue.append([currentLevel, currentNode.right])
            rightView = []
            for level in levelNodes:
                rightView.append(levelNodes[level][-1])
            return rightView
        return []

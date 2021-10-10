# Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node. 

[![Tree1](tree1.png)]()

### Example 1
```sh
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

[![Tree2](tree2.png)]()
### Example 2
```sh
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

[![Tree3](tree3.png)]()
### Example 3
```sh
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

### Constraints
```sh
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
```

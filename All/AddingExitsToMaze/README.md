# Adding Exits to a Maze

Now you decide to make sure that there are no dead zones in a maze, that is, that at least one exit is
reachable from each cell. For this, you find connected components of the corresponding undirected graph
and ensure that each component contains an exit cell.

**Task:** Given an undirected graph with 𝑛 vertices and 𝑚 edges, compute the number of connected components
in it.

**Input Format:** A graph is given in the standard format.

**Output Format:** Output the number of connected components.

### Example 1
```sh
Input:  42
        12
        32  
Output: 2
```

### Example 2
```sh
Input:  43
        12
        32
        14  
Output: 1
```

### Constraints
```sh
1 <= 𝑛 <= 10^3
0 <= 𝑚 <= 10^3.
```

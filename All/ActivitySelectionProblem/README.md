# Activity Selection problem

You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

### Example 1
```sh
Input: activities[] = [[10,20], [12,25], [20,30]]  
Output: 2
Explanation: A person can perform at most two activities. The maximum set of activities that can be executed is {0, 2} [ These are indexes in activities[] ]
```

### Example 2
```sh
Input: activities[] = [[1,2], [3,4], [0,6], [5,7], [8,9], [5,9]]  
Output: 4
Explanation: A person can perform at most two activities. The maximum set of activities that can be executed is {0, 1, 3, 4} [ These are indexes in activities[] ] 
```

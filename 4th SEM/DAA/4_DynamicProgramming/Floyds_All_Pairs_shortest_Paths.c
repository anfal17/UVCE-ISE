/*
The given algorithm implements Floyd's algorithm for solving the all-pairs shortest-paths problem. Let's break down its key components:

Algorithm Overview:

Objective: Find the shortest paths between all pairs of vertices in a graph with no negative-length cycles.
Input: The weight matrix W representing the edge weights of the graph.
Output: The distance matrix D representing the lengths of the shortest paths between all pairs of vertices.
Initialization:

D ← W: Initializes the distance matrix D with the initial values from the weight matrix W. This step may not be necessary if W can be overwritten.
Floyd's Algorithm Main Loop:

The algorithm uses a triple-nested loop to consider all vertices as intermediate vertices in the paths.
The outer loop (for k ← 1 to n) represents considering vertices 1, 2, ..., n as intermediate vertices.
The middle loop (for i ← 1 to n) represents the source vertex.
The inner loop (for j ← 1 to n) represents the destination vertex.
For each pair of vertices i and j, the algorithm updates the distance matrix D with the minimum of the current distance and the sum of distances through the intermediate vertex k:
D[i, j] ← min{D[i, j], D[i, k] + D[k, j]}.
Return Result:

The final result is the updated distance matrix D.
*/


ALGORITHM Floyd(W[1..n, 1..n])
// Implements Floyd’s algorithm for the all-pairs shortest-paths problem
// Input: The weight matrix W of a graph with no negative-length cycle
// Output: The distance matrix of the shortest paths’ lengths

D ← W // Initialization of distance matrix
for k ← 1 to n do
    for i ← 1 to n do
        for j ← 1 to n do
            D[i, j] ← min{D[i, j], D[i, k] + D[k, j]}

return D


TC- Cubic O(n^3)
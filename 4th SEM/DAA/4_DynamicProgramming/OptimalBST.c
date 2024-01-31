ALGORITHM OptimalBST(P[1..n])
// Finds an optimal binary search tree using dynamic programming
// Input: An array P[1..n] of search probabilities for a sorted list of n keys
// Output: Average number of comparisons in successful searches in the
// optimal BST (C[1, n]) and table R of subtrees’ roots in the optimal BST

// Initialization
for i ← 1 to n do
    C[i, i - 1] ← 0 //representing the case with no keys
    C[i, i] ← P[i] // and a single key.
    R[i, i] ← i //the root of a single-node tree.
C[n + 1, n] ← 0

// Dynamic Programming Loop
for d ← 1 to n - 1 do //iterates over diagonals in the tables
    for i ← 1 to n - d do //iterates over the subproblems within each diagonal.
        j ← i + d 
        minval ← ∞
        for k ← i to j do 
            if C[i, k - 1] + C[k + 1, j] < minval
                minval ← C[i, k - 1] + C[k + 1, j]
                kmin ← k
        R[i, j] ← kmin //min root value
        sum ← P[i]; for s ← i + 1 to j do sum ← sum + P[s] //sum of all probailities
        C[i, j] ← minval + sum

// Returning Results
return C[1, n], R

//Time Complexity - quadratic O(n^2)


ALGORITHM MFKnapsack(i, j)
// Implements the memory function method for the knapsack problem
// Input: Nonnegative integers i (items being considered) and j (knapsack capacity)
// Output: The value of an optimal feasible subset

// Check if the value for the current state is already computed
if F[i, j] < 0
    // If not, calculate the value using recursion with memoization
    if j < Weights[i]
        // If the current item cannot fit into the remaining knapsack capacity,
        // exclude it and recursively calculate the value
        value ← MFKnapsack(i - 1, j)
    else
        // Otherwise, consider two possibilities: excluding the current item
        // or including it and recursively calculating the value
        value ← max(MFKnapsack(i - 1, j), Values[i] + MFKnapsack(i - 1, j - Weights[i]))
    
    // Store the calculated value in the memoization table
    F[i, j] ← value

// Return the value for the current state
return F[i, j]

/*

*/

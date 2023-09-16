#include <stdio.h>

#define N 8 // You can change N to any positive integer

int board[N][N]; // Chessboard

// Function to check if it's safe to place a queen at (row, col)
int isSafe(int row, int col) {
    // Check the left side of the current column
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    
    // Check the upper diagonal on the left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    // Check the lower diagonal on the left
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }

    return 1; // It's safe to place a queen here
}

// Function to solve the N-Queens problem using backtracking
int solveNQueens(int col) {
    if (col >= N) {
        return 1; // All queens are placed successfully
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; // Place the queen

            if (solveNQueens(col + 1)) {
                return 1; // If it leads to a solution, return
            }

            board[i][col] = 0; // If not, backtrack
        }
    }

    return 0; // No solution found
}

// Function to print the solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the chessboard
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0)) {
        printf("Solution:\n");
        printSolution();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

/*
isSafe(int row, int col): This function checks if it's safe to place a queen at the given position (row, col) on the chessboard. It ensures that no other queens threaten the queen being placed. It checks three conditions:

No two queens share the same column.
No two queens share the same upper diagonal (top-left to bottom-right).
No two queens share the same lower diagonal (bottom-left to top-right).
solveNQueens(int col): This is the core recursive function for solving the N-Queens problem. It attempts to place queens in each column, starting from column col (initially, col is 0) to N-1. The function follows these steps:

If col is greater than or equal to N, it means all queens are placed successfully, so it returns 1 to indicate success.
For each row i from 0 to N-1, it checks if it's safe to place a queen at (i, col) using the isSafe function.
If it's safe, it marks (i, col) as a valid queen placement by setting board[i][col] to 1.
Then, it recursively calls itself with col + 1 to try placing queens in the next column.
If this recursive call returns 1 (indicating success), the function also returns 1.
If the recursive call returns 0 (no solution was found in the subsequent columns), it backtracks by setting board[i][col] back to 0 and continues checking other rows.
If no solution is found for all rows in the current column, it returns 0 to indicate failure.
printSolution(): This function is responsible for printing the solution to the N-Queens problem. It simply iterates through the board array and prints the queens' positions as a chessboard configuration.

main(): This is the main function where the program execution starts. It initializes the chessboard by setting all elements to 0. Then, it calls the solveNQueens function to find a valid solution for placing N queens. If a solution is found, it prints the solution using printSolution. If no solution is found, it prints a message indicating that no solution exists.

In summary, the backtracking algorithm works by recursively exploring all possible queen placements on the chessboard and backtracking whenever it finds that a certain placement doesn't lead to a valid solution. This process continues until a valid solution is found or all possibilities are exhausted



Explaining Backtracking to a Child:

Okay, imagine you're doing a maze puzzle. You start at the entrance, and your goal is to find your way to the exit. You can only move one step at a time, and you need to make decisions about which path to take.

Now, let's say you start down one path, and you realize it's a dead-end; you can't reach the exit from there. What do you do? You backtrack! Backtracking means you go back to where you made the wrong choice, and you try a different path. You keep doing this until you find the right path to the exit.

So, backtracking is like exploring a maze. You try different paths, and if you get stuck, you go back and try another one until you reach your goal.

Explaining Backtracking to a Computer Science Student:

In computer science, backtracking is a powerful algorithmic technique used to solve problems where you need to find the best solution among a set of choices. It's often used for combinatorial problems like puzzles, optimization, and searching.

Here's how it works:

Exploring Choices: You start with an initial choice or decision. This choice may lead to a series of subproblems or further decisions.

Recursive Approach: You explore these choices recursively, meaning you delve deeper into a decision tree. Each choice creates a branch in the tree.

Constraints and Conditions: At each step, you check if the current choice satisfies certain conditions or constraints. If it does, you continue exploring that branch.

Backtrack: If a choice doesn't meet the conditions or leads to a dead-end, you backtrack. This means you go back to the previous decision point and explore other branches.

Repeat: You repeat this process until you find a solution or exhaust all possible choices. If you find a solution, you return it; otherwise, you report that no solution exists.

For example, backtracking can be used to solve puzzles like the N-Queens problem, Sudoku, or the Traveling Salesman Problem. In these cases, you make choices (placing queens on a chessboard, filling Sudoku cells, or selecting cities to visit), check if they meet certain conditions (no queens attacking each other, valid Sudoku rules, shortest path), and backtrack when conditions are violated or when you've explored all possibilities.

Backtracking is a systematic way to search for solutions in a problem space while intelligently discarding unpromising paths, making it an essential technique in algorithm design and problem-solving
*/
#include<iostream>
using namespace std;

// Define a class 'dj' to encapsulate the functionality for Dijkstra's algorithm
class dj {
    int n; // Number of vertices/nodes in the network
    int cost[10][10]; // Cost adjacency matrix to hold the costs of edges between nodes
    int d[10]; // Array to hold the shortest distance from the source node to each node
    int p[10]; // Array to hold the predecessor node on the shortest path from the source
    int v[10]; // Array to mark nodes as visited during the algorithm

public:
    // Method to read the cost adjacency matrix from the user
    void read_matrix() {
        int i, j;
        cout << "Enter the number of vertices\n";
        cin >> n;
        cout << "Enter the cost adjacency matrix\n";
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin >> cost[i][j];
    }

    // Method to find the shortest path from a given source node
    void short_path(int src) {
        int i, j, min, u, s;
        // Initialize distances and mark source node as visited
        for(i = 0; i < n; i++) {
            d[i] = cost[src][i];
            v[i] = 0;
            p[i] = src;
        }
        v[src] = 1; // Mark source node as visited

        // Main loop of Dijkstra's algorithm
        for(i = 0; i < n; i++) {
            min = 99; // Initialize min to a large value
            u = 0; // Initialize u to 0
            // Find the unvisited node with the smallest distance
            for(j = 0; j < n; j++) {
                if(!v[j]) { // Check if node j is not visited
                    if(d[j] < min) {
                        min = d[j];
                        u = j;
                    }
                }
            }
            v[u] = 1; // Mark node u as visited

            // Relax all edges of the selected node
            for(s = 0; s < n; s++) {
                if(!v[s] && (d[u] + cost[u][s] < d[s])) {
                    d[s] = d[u] + cost[u][s];
                    p[s] = u;
                }
            }
        }
    }

    // Method to display the shortest path from the source node to all other nodes
    void display(int src) {
        int i, k, parent;
        for(i = 0; i < n; i++) {
            if(i == src) continue; // Skip the source node
            cout << "The shortest path from " << src << " to " << i << " is " << endl;
            k = i;
            cout << k << "<----";
            while(p[k]!= src) {
                cout << p[k] << "<---"; // Display the path
                k = p[k];
            }
            cout << src << endl;
            cout << "and the distance is " << d[i] << endl; // Display the distance
        }
    }
};

int main() {
    int source;
    dj dij; // Create an object of class 'dj'
    
    // Read the cost matrix from the user
    dij.read_matrix();
    
    // Ask the user for the source node
    cout << "Enter the source node:" << endl;
    cin >> source;
    
    // Calculate the shortest paths from the source node
    dij.short_path(source);
    
    // Display the shortest paths and distances
    dij.display(source);
    
    return 0;
}
#include <iostream>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to find set of an element in the union-find structure
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement bubble sort for sorting edges based on weight
void bubbleSort(Edge edges[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges[j] and edges[j + 1]
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(Edge edges[], int V, int E) {
    // Sort the edges in non-decreasing order of their weights
    bubbleSort(edges, E);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    Edge result[V - 1]; // to store the result MST
    int idx = 0; // Index for the result array

    // Process each edge in sorted order
    for (int i = 0; i < E && idx < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        // If including this edge does not cause a cycle, add it to the result
        if (x != y) {
            result[idx++] = edges[i];
            Union(subsets, x, y);
        }
    }

    // Print the result MST
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < V - 1; i++) {
        cout << result[i].src << " -- " << result[i].dest << "   Weight: " << result[i].weight << endl;
    }

    // Clean up memory
    delete[] subsets;
}

int main() {
    // Example graph represented by its edges and weights
    Edge edges[] = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };

    int V = 9; // Number of vertices in the graph
    int E = sizeof(edges) / sizeof(edges[0]); // Number of edges in the graph

    kruskalMST(edges, V, E);

    return 0;
}

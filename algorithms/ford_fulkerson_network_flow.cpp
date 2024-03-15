#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
#define V 6

// parent[] will have indices representing each vertex
// value at an index will show index of the parent vertex
// eg: -1 2 0 3 means A->C->B->D

bool bfs(int rGraph[V][V], int s, int t, int parent[]) {

    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Visit the source vertex
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                
                // If we find connection to sink,
                // then our path is complete.
                if (v == t) {
                    parent[v] = u;
                    return true;
                }

                // Getting other vertex means we
                // continue building path
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // False if we couldn't reach sink
    return false;
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Represents residual graph of algorithm
    int rGraph[V][V];

    // Copy the first residual graph as original graph
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }
 
    int parent[V]; // We will get this from our bfs function
    int max_flow = 0; // There is no flow initially
 
    // Our algorithm adds flow until path to sink disappears
    while (bfs(rGraph, s, t, parent)) {

        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
 
// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 },
            { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },
            { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },
            { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
 
    return 0;
}
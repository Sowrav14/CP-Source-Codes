#include <bits/stdc++.h>
using namespace std;

// Perform DFS to count the in-degree
// and out-degree of the graph
void dfs(int u, vector<int> adj[], int* vis, int* inDeg,
         int* outDeg)
{
    // Mark the source as visited
    vis[u] = 1;

    // Traversing adjacent nodes
    for (auto v : adj[u])
    {
        // Mark out-degree as 1
        outDeg[u] = 1;
        // Mark in-degree as 1
        inDeg[v] = 1;

        // If not visited
        if (vis[v] == 0)
        {
            // DFS Traversal on
            // adjacent vertex
            dfs(v, adj, vis, inDeg, outDeg);
        }
    }
}

// Function to return minimum number
// of edges required to make the graph
// strongly connected
int findMinimumEdges(int source[], int N, int M, int dest[])
{
    // For Adjacency List
    vector<int> adj[N + 1];

    // Create the Adjacency List
    for (int i = 0; i < M; i++)
    {
        adj[source[i]].push_back(dest[i]);
    }

    // Initialize the in-degree array
    int inDeg[N + 1] = {0};

    // Initialize the out-degree array
    int outDeg[N + 1] = {0};

    // Initialize the visited array
    int vis[N + 1] = {0};

    // Perform DFS from all unvisited vertices
    for (int i = 1; i <= N; ++i)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, inDeg, outDeg);
        }
    }

    // To store the result
    int minEdges = 0;

    // To store total count of in-degree
    // and out-degree
    int totalIndegree = 0;
    int totalOutdegree = 0;

    // Find total in-degree
    // and out-degree
    for (int i = 1; i <= N; i++)
    {
        if (inDeg[i] == 1)
            totalIndegree++;
        if (outDeg[i] == 1)
            totalOutdegree++;
    }

    // Calculate the minimum
    // edges required
    minEdges = max(N - totalIndegree, N - totalOutdegree);
    cout << totalIndegree << " " << totalOutdegree << endl;

    // Return the minimum edges
    return minEdges;
}

// Driver Code
int main()
{
    int N = 7, M = 7;

    int source[] = {1, 2, 3, 6, 6, 4, 7};
    int destination[] = {2, 3, 1, 1, 4, 5, 6};

    // Function call
    cout << findMinimumEdges(source, N, M, destination);
    return 0;
}

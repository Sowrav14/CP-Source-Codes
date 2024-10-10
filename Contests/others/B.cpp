#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int MAX_BITS = 61;  // We consider up to 60 bits for large edge weights.
vector<vector<pair<int, int>>> adj;  // Adjacency list for the tree (node, weight)
vector<long long> xor_from_root;     // Stores the XOR from the root to each node
const int M = 1e9+7;
// DFS to compute the XOR values of each node from the root (node 1)
void dfs(int node, int parent, long long current_xor) {
    xor_from_root[node] = current_xor;
    for (auto [neighbor, weight] : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, current_xor ^ weight);
        }
    }
}

long long calculate_total_xor_sum(int n) {
    long long total_sum = 0;

    // For each bit from 0 to MAX_BITS-1
    for (int bit = 0; bit < MAX_BITS; ++bit) {
        long long count_ones = 0;  // Count of nodes where the 'bit'th bit is 1

        // Count the number of nodes with the current bit set to 1
        for (int i = 1; i <= n; ++i) {
            if (xor_from_root[i] & (1LL << bit)) {
                count_ones++;
            }
        }

        // The number of pairs with different bit values is count_ones * (n - count_ones)
        long long count_zeros = (n%M - count_ones%M + M)%M;
        long long pairs_with_different_bits = (count_ones%M * count_zeros%M)%M;
        
        // Each pair contributes 2^bit to the sum for this bit
        int x = (pairs_with_different_bits%M * (1LL << bit)%M)%M;
        total_sum = (total_sum%M + x%M)%M;
    }

    return total_sum;
}

signed main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    xor_from_root.resize(n + 1);

    // Read the tree edges
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Start DFS from node 1 (or any arbitrary root)
    dfs(1, -1, 0);

    // Calculate the total sum of XOR distances
    long long result = calculate_total_xor_sum(n);
    cout << result << endl;

    return 0;
}

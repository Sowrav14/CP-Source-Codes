#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<long long>> dp;

// Fill current column given the mask of occupied cells
void fill(int col, int pos, int cur_mask, int next_mask, long long ways) {
    if (pos == n) {
        // Finished filling current column
        dp[col + 1][next_mask] = (dp[col + 1][next_mask] + ways) % MOD;
        return;
    }
    
    if (cur_mask & (1 << pos)) {
        // Current cell is already occupied by vertical tile from previous column
        fill(col, pos + 1, cur_mask, next_mask, ways);
    } else {
        // Current cell is empty, we have options:
        
        // Option 1: Place vertical tile (2x1) - occupies current cell and next column
        fill(col, pos + 1, cur_mask, next_mask | (1 << pos), ways);
        
        // Option 2: Place horizontal tile (1x2) - occupies current cell and next cell
        if (pos + 1 < n && !(cur_mask & (1 << (pos + 1)))) {
            fill(col, pos + 2, cur_mask, next_mask, ways);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    // dp[col][mask] = ways to fill columns 0..col-1 completely
    // mask = which cells in column 'col' are occupied by vertical tiles
    dp.assign(m + 1, vector<long long>(1 << n, 0));
    
    dp[0][0] = 1; // Base case: no columns filled, no occupied cells
    
    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[col][mask] > 0) {
                fill(col, 0, mask, 0, dp[col][mask]);
            }
        }
    }
    
    cout << dp[m][0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
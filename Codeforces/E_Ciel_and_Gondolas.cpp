/**
 * @file E_Ciel_and_Gondolas.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-01-08
 * @copyright Copyright (c) 2025
 * @tag: divide_and_conquer_dp dp divide and conquer
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 4000+ 10;
const int K = 800 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, k;
int a[N][N], c[N][N], dp[K][N];

// cost if i to j belongs to same group...
int cost(int i, int j) {
	return c[j][j] - c[i - 1][j] - c[j][i - 1] + c[i - 1][i - 1];
}

void divide_and_conquer_dp(int i, int l, int r, int optl, int optr) {
	if(l > r) return;
	int mid = (l + r) / 2;
	dp[i][mid] = inf;
	int opt = -1;
	for(int k = optl; k <= min(mid - 1, optr); k++) {
		int c = dp[i - 1][k] + cost(k + 1, mid);
		if(c < dp[i][mid]) {
			dp[i][mid] = c;
			opt = k;
		}
	}
	// for opt[1..j] <= opt[1...j+1]
	if (opt == -1) {
        // if we can't divide into k parts, then go right
		divide_and_conquer_dp(i, mid + 1, r, optl, optr);
		return;
	}
	divide_and_conquer_dp(i, l, mid - 1, optl, opt);
	divide_and_conquer_dp(i, mid + 1, r, opt, optr);

}

void solve(){

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
			char ch; cin >> ch;
            a[i][j] = ch - '0';
            c[i][j] = a[i][j] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = inf;
        }
    }
    // for the first group all will be included.
	for(int i=1;i<=n;i++) dp[1][i] = cost(1, i);

    for(int i=2;i<=k;i++){
        divide_and_conquer_dp(i, 1, n, 1, n);
    }
    cout << dp[k][n] / 2 << endl;
}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
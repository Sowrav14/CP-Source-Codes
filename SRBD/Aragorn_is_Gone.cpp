#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T))
        return 0;
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        ll ans = 0;
        for (int k = 1; k <= N; k++)
        {
            vector<vector<ll>> dp(k + 1, vector<ll>(k, 0));
            dp[0][0] = 1;
            for (int i = 0; i < N; i++)
            {
                int r = ((a[i] % k) + k) % k;
                int up = min(i, k - 1);
                for (int c = up; c >= 0; c--)
                {
                    for (int rem = 0; rem < k; rem++)
                    {
                        int to = rem + r;
                        if (to >= k)
                            to -= k;
                        dp[c + 1][to] = (dp[c + 1][to] + dp[c][rem]) % MOD;
                    }
                }
            }
            ans = (ans + dp[k][0]) % MOD;
        }
        cout << "Case " << tc << ": " << ans << "\n";
    }
    return 0;
}

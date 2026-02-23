#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int modpow(int a, int b) {
    int r = 1;
    while (b > 0) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int inv(int x) { return modpow(x, MOD - 2); }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> prefMax(n + 1, 0);
    vector<int> isLeader(n + 1, 0), isCo(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefMax[i] = max(prefMax[i - 1], a[i]);
        if (a[i] > prefMax[i - 1]) isLeader[i] = 1;
        else if (a[i] == prefMax[i - 1]) isCo[i] = 1;
    }

    vector<int> lastLeader(n + 1, 0);
    for (int i = 1; i <= n; i++)
        lastLeader[i] = isLeader[i] ? i : lastLeader[i - 1];

    // streak of girls who are NOT strictly better than the current max
    vector<int> streak(n + 1, 0), maxStreakPref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (isLeader[i]) streak[i] = 0;
        else streak[i] = streak[i - 1] + 1;
        maxStreakPref[i] = max(maxStreakPref[i - 1], streak[i]);
    }

    vector<int> prefCo(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefCo[i] = prefCo[i - 1] + isCo[i];

    auto get_prob = [&](int i, int k) {
        // 1. Check if reached: longest streak of non-leaders BEFORE i must be < k
        if (i > 1 && maxStreakPref[i - 1] >= k) return 0LL;

        // 2. Probability of becoming current favorite
        int prob_fav;
        if (isLeader[i]) prob_fav = 1;
        else if (isCo[i]) prob_fav = inv(2);
        else return 0LL;

        // 3. Probability of staying favorite until Shanto sleeps
        // Shanto sleeps at index r = min(n, last_leader_pos + k)
        int L = lastLeader[i];
        int r = min(n, L + k);

        // If a new leader appears before Shanto sleeps, girl i is replaced
        if (lastLeader[r] > i) return 0LL;

        // Any co-leaders between i and r must lose their toss
        int co_count = prefCo[r] - prefCo[i];
        int prob_stay = modpow(inv(2), co_count);

        return prob_fav * prob_stay % MOD;
    };

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, k; cin >> i >> k;
            cout << get_prob(i, k) << "\n";
        } else {
            int i; cin >> i;
            if (!isLeader[i] && !isCo[i]) {
                cout << "1 0\n";
                continue;
            }
            // To maximize probability:
            // k must be >= maxStreakPref[i-1] + 1 to reach girl i.
            // Smallest such k minimizes the window (r = L + k) to exclude future competitors.
            int k_opt = maxStreakPref[i - 1] + 1;
            cout << k_opt << " " << get_prob(i, k_opt) << "\n";
        }
    }

    return 0;
}
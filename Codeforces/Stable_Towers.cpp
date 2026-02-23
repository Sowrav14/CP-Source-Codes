#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> prevRow(M), curRow(M);
    vector<int> dpPrev(M, 1), dpCur(M);

    // read first row
    for (int j = 0; j < M; j++) cin >> prevRow[j];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> curRow[j];

        long long sumWays = 0;
        int p = 0;  // pointer in prevRow

        for (int j = 0; j < M; j++) {
            while (p < M && prevRow[p] < curRow[j]) {
                sumWays += dpPrev[p];
                if (sumWays >= MOD) sumWays -= MOD;
                p++;
            }
            dpCur[j] = (int)sumWays;
        }

        // move to next
        prevRow.swap(curRow);
        dpPrev.swap(dpCur);
    }

    long long ans = 0;
    for (int j = 0; j < M; j++) {
        ans += dpPrev[j];
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}
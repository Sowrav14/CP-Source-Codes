#include<bits/stdc++.h>
using namespace std;

double dfs(vector<int> a) {
    int k = a.size();
    if (k == 1) return 0.0;

    double res = 0.0;
    double pairProb = 1.0 / (k * (k - 1) / 2);

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            double score = abs(a[i] - a[j]);

            vector<int> b;

            // drop i
            b.clear();
            for (int t = 0; t < k; t++)
                if (t != i) b.push_back(a[t]);
            res += pairProb * 0.5 * (score + dfs(b));

            // drop j
            b.clear();
            for (int t = 0; t < k; t++)
                if (t != j) b.push_back(a[t]);
            res += pairProb * 0.5 * (score + dfs(b));
        }
    }
    return res;
}

int main() {
    vector<int> a = {1, 4, 3, 5};
    cout << fixed << setprecision(10) << dfs(a) << "\n";
}

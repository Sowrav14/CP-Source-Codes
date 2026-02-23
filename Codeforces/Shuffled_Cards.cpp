#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int total_swaps = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int curr = i;
            int cycle_size = 0;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = a[curr];
                cycle_size++;
            }
            total_swaps += (cycle_size - 1);
        }
    }


    if (total_swaps % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
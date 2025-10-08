#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int Q;
    cin >> Q;

    list<int> seq;
    unordered_map<int, list<int>::iterator> pos;

    seq.push_back(0);
    pos[0] = seq.begin();

    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            auto it = pos[x];
            it++; // insert after x
            auto new_it = seq.insert(it, i);
            pos[i] = new_it;
        } else {
            int x, y;
            cin >> x >> y;
            auto it1 = pos[x], it2 = pos[y];
            if (it1 == it2) { cout << 0 << "\n"; continue; }
            // ensure it1 comes before it2
            if (distance(seq.begin(), it1) > distance(seq.begin(), it2)) swap(it1, it2);

            auto start = next(it1);
            auto end = it2;
            long long sum = 0;
            for (auto it = start; it != end; it++) sum += *it;
            seq.erase(start, end);
            cout << sum << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

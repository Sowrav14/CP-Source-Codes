#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> id(n, -1);
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '0') id[i] = cnt++;
    }

    vector<vector<pair<int, int>>> adj(cnt);
    vector<int> fixed(cnt, -1);
    bool ans = true;
    for (int j = 0; j < n; j++) {
        if (s[j] == '1') {
            int left = j - 1, right = j + 1;
            bool lzero = (left >= 0 && s[left] == '0'), rzero = (right < n && s[right] == '0');
            if (lzero && rzero) {
                int u = id[left], v = id[right];
                adj[u].push_back({v, 1});
                adj[v].push_back({u, 1});
            } else if (lzero) {
                int u = id[left];
                if (fixed[u] == 1) ans = false;
                fixed[u] = 0;
            } else if (rzero) {
                int v = id[right];
                if (fixed[v] == 0) ans = false;
                fixed[v] = 1;
            }
        }
    }
    if (!ans) {
        cout << "NO" << endl;
        return;
    }
    vector<int> val(cnt, -1);
    queue<int> q;
    for (int i = 0; i < cnt && ans; i++) {
        if (fixed[i] != -1 && val[i] == -1) {
            val[i] = fixed[i];
            q.push(i);
            while (!q.empty() && ans) {
                int u = q.front();
                q.pop();
                for (auto [v, p] : adj[u]) {
                    int expect = val[u] ^ p;
                    if (val[v] == -1) {
                        val[v] = expect;
                        q.push(v);
                    } else if (val[v] != expect) {
                        ans = false;
                        break;
                    }
                }
            }
        }
    }
    if (!ans) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < cnt && ans; i++) {
        if(val[i] == -1) {
            val[i] = 0;
            q.push(i);
            while(!q.empty() && ans) {
                int u = q.front();
                q.pop();
                for(auto [v, p] : adj[u]) {
                    int expect = val[u] ^ p;
                    if(val[v] == -1) {
                        val[v] = expect;
                        q.push(v);
                    } else if(val[v] != expect) {
                        ans = false;
                        break;
                    }
                }
            }
        }
    }
    if(!ans) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < cnt; i++) {
        if(fixed[i] != -1 && val[i] != fixed[i]) ans = false;
    }
    cout << (ans ? "YES" : "NO") << endl;
}

signed main() {
    Fast_IO()
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
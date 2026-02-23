#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
const int N = 3010; // n ≤ 3000

struct BIT {
    int size;
    vector<int> bit;

    void init(int n) {
        size = n;
        bit.assign(n+2, 0);
    }

    void update(int idx, int val) {
        while(idx <= size){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int range_query(int l, int r){
        return query(r) - query(l-1);
    }
};

int g[N][N];
int vis[N][N];
BIT bits[N];

int n;

void solve(){
    int c; cin >> n >> c;

    // clear vis
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) vis[i][j] = 0;
    }

    for(int j=1;j<=n;j++) bits[j].init(n);

    for(int i=1;i<=n;i++){
        string s; cin >> s;
        for(int j=1;j<=n;j++){
            g[i][j] = (s[j-1] == '#' ? 1 : 0);
            if(g[i][j] == 1) bits[j].update(i, 1);
        }
    }

    function<void(int,int)> dfs = [&](int i, int j){
        if(i < 1 || j < 1 || j > n) return;
        if(vis[i][j]) return;
        vis[i][j] = 1;

        // move to three directions: (i-1,j-1),(i-1,j),(i-1,j+1)
        for(int dc=-1; dc<=1; dc++){
            int nj = j + dc;
            int ni = i - 1;
            if(ni < 1 || nj < 1 || nj > n) continue;
            if(vis[ni][nj]) continue;

            if(g[ni][nj] == 0){
                dfs(ni, nj);
            }else{
                // wall: check if all below are empty
                if(bits[nj].range_query(ni+1, n) == 0){
                    bits[nj].update(ni, -1); // destroy wall
                    g[ni][nj] = 0; // mark as empty
                    dfs(ni, nj);
                }
            }
        }
    };

    dfs(n, c);

    for(int j=1;j<=n;j++){
        cout << (vis[1][j] ? 1 : 0);
    }
    cout << endl;
}

signed main(){
    Fast_IO()
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

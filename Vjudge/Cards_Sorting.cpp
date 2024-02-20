#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 100010;
int bit[N];
set<int>g[N];
priority_queue<int, vector<int>, greater<int>>pq;
int n;

// updating a single value in bit
void update(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += (idx) & (-idx);  // lsb will be added.
    }
}

// return sum of (1 - idx)
int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);  // lsb will be substracted.
    }
    return ret;
}




void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        update(i, 1);
        g[x].insert(i);
        pq.push(x);
    }
    int ans = 0;
    int prev = 1;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();

        // int cur = lower_bound(g[x].begin(), g[x].end(), prev) - g[x].begin();
        auto it = g[x].lower_bound(prev);
        if(it == g[x].end()){
            it = g[x].begin();
        }
        int cur = *it;

        int res;
        if(cur >= prev){
            // [1...cur] - [1...prev]
            int r = query(cur);
            int l = query(prev-1);
            res = r - l;
        } else{
            // [1...n] - [1...prev] + [1...cur]
            int p = query(n);
            int q = query(prev-1);
            int r = query(cur);
            res = p - q + r;
        }

        // cout << x << " " << prev << " " << cur << " " << res << endl;

        ans += res;
        update(cur, -1);
        g[x].erase(it);
        prev = cur;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct SegmentTree {
    int size;
    vector<int> tree;
    SegmentTree(int n) : size(n) {
        tree.assign(4 * n + 10, 0);
    }
    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(idx, val, 2 * node, l, mid);
        else update(idx, val, 2 * node + 1, mid + 1, r);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int idx, int val) {
        update(idx, val, 1, 1, size);
    }
    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(ql, qr, 2 * node, l, mid), query(ql, qr, 2 * node + 1, mid + 1, r));
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(l, r, 1, 1, size);
    }
};

void solve(){

    int n; cin >> n;
    vector<int> a(n+1);
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) v.push_back({a[i], i});
    sort(v.begin(), v.end());

    vector<int> left(n+2, 0), right(n+2, n+1);
    stack<pair<int,int>> st;
    // Next greater to left
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().first < a[i]) st.pop();
        if (!st.empty()) left[i] = st.top().second;
        else left[i] = 0;
        st.push({a[i], i});
    }
    while (!st.empty()) st.pop();
    // Next greater to right
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.top().first < a[i]) st.pop();
        if (!st.empty()) right[i] = st.top().second;
        else right[i] = n + 1;
        st.push({a[i], i});
    }

    // for(int i=1;i<=n;i++) cout << left[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << right[i] << " "; cout << endl;

    SegmentTree seg(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        int x = v[i].first, id = v[i].second;
        int l = left[id], r = right[id];

        int cur = seg.query(l + 1, r - 1) + 1;
        seg.update(id, cur); 
        mx = max(mx, cur);
    }
    cout << mx << endl;

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
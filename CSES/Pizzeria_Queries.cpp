#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lc (n << 1)
#define rc ((n << 1) | 1)
const int N = 2e5 + 10;

// Structuring Segment Tree...
struct SegmentTree {
	int tree[4*N];
	SegmentTree() {
        for(int i=0;i<4*N;i++) tree[i] = INT_MAX;
    }

    void update(int i, int l, int r, int k, int val) {
		if (l == r) {
			tree[i] = val;
			return;
		}
		int m = (l + r) / 2;
		if (k <= m) update(i * 2, l, m, k, val);
		else update(i * 2 + 1, m + 1, r, k, val);
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}

	int query(int n, int b, int e, int i, int j) {
		if (i > e || b > j) return INT_MAX;	// what??
		if (i <= b && e <= j) return tree[n];
		int mid = (b + e) >> 1;
		return min(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
	}
};


void solve(){

    int n,q; cin >> n >> q;
    vector<int> v(n+1, 0);
	for(int i=1;i<=n;i++){
		cin >> v[i];
	}

	SegmentTree up, down;
    for(int i=1;i<=n;i++) up.update(1, 1, n, i, v[i] + i);
    for(int i=1;i<=n;i++) down.update(1, 1, n, i, v[i] - i);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int id, val; cin >> id >> val;
            up.update(1, 1, n, id, val + id);
            down.update(1, 1, n, id, val - id);
        } else{
            int id; cin >> id;
            int ans1 = up.query(1, 1, n, id, n) - id;
            int ans2 = down.query(1, 1, n, 1, id) + id;
            cout << min(ans1, ans2) << endl;
        }
    }
	

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
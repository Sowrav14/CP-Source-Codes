#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lc (n << 1)
#define rc ((n << 1) | 1)
const int N = 2e5 + 10;
int a[N];

// Structuring Segment Tree...
struct SegmentTree {
	int tree[4*N] = {0};
	SegmentTree() {}

	// combine two node of segment tree... how??
	inline int combine(int a,int b) {
		return a xor b;
	}
	inline void pull(int n) {
		tree[n] = tree[lc] xor tree[rc];
	}
	// building the segment tree...
	void build(int n, int b, int e) {
		if (b == e) {
    		tree[n] = a[b];
    		return;
		}
		int mid = (b + e) >> 1;
		build(lc, b, mid);
		build(rc, mid + 1, e);
		pull(n);
	}
	// range query...
	int query(int n, int b, int e, int i, int j) {
		if (i > e || b > j) return 0;	// what??
		if (i <= b && e <= j) return tree[n];
		int mid = (b + e) >> 1;
		return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
	}
};


void solve(){

    int n,q; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	SegmentTree temp;
	temp.build(1, 1, n); 
    // cout << (1 xor 2) << endl;
    while(q--){
        int l,r; cin >> l >> r;
        cout << temp.query(1, 1, n, l, r) << endl;
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
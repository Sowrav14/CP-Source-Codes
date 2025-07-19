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
           tree[node] = (tree[node] + val) % M;
           return;
       }
       int mid = (l + r) / 2;
       if (idx <= mid) update(idx, val, 2 * node, l, mid);
       else update(idx, val, 2 * node + 1, mid + 1, r);
       tree[node] = (tree[2 * node] + tree[2 * node + 1]) % M;
   }
   void update(int idx, int val) {
       update(idx, val, 1, 1, size);
   }
   int query(int ql, int qr, int node, int l, int r) {
       if (qr < l || ql > r) return 0;
       if (ql <= l && r <= qr) return tree[node];
       int mid = (l + r) / 2;
       return (query(ql, qr, 2 * node, l, mid) + query(ql, qr, 2 * node + 1, mid + 1, r)) % M;
   }
   int query(int l, int r) {
       if (l > r) return 0;
       return query(l, r, 1, 1, size);
   }
};


vector<int> compress(const vector<int>& a) {
   vector<int> vals = a;
   sort(vals.begin(), vals.end());
   vals.erase(unique(vals.begin(), vals.end()), vals.end());
   vector<int> res(a.size());
   for (size_t i = 0; i < a.size(); ++i) {
       res[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
   }
   return res;
}


void solve(){

   int n; cin >> n;
   vector<int> a(n);
   for(int i=0;i<n;i++) cin >> a[i];
   a = compress(a);
   SegmentTree seg(n);

   int ans = 0;
   for(int i=0;i<n;i++){
       int x = a[i];
       int cur = seg.query(1, x - 1);
       ans = (ans + cur + 1) % M;
       seg.update(x, cur + 1);
   }
   cout << ans << endl;

}


signed main(){
   Fast_IO()
   int t = 1;
   for(int i=1;i<=t;i++){
       solve();
   }
}
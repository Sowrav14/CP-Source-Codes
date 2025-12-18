#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, q;

int val[N];
vector<int> adj[N];
int sub[N], dep[N], par[N];
int head[N] , st[N] , en[N] , clk;
int dfsarr[N];

/* Segment Tree for Euler Tour Technique */

struct LazySeg {
  int n;
  vector<int> t, lz;
  LazySeg(int n){
    this->n = 1;
    while(this->n < n) this->n <<= 1;
    t.assign(2*this->n, -inf);
    lz.assign(this->n, 0);
  }
  void apply(int p, int val){
    t[p] += val;
    if(p < n) lz[p] += val;
  }
  void push(int p){
    apply(p<<1, lz[p]);
    apply(p<<1|1, lz[p]);
    lz[p] = 0;
  }
  void push_path(int p){
    for(int h = __lg(n); h > 0; h--){
      int x = p >> h;
      if(lz[x]) push(x);
    }
  }
  void pull(int p){
    while(p > 1){
      p >>= 1;
      t[p] = max(t[p<<1], t[p<<1|1]) + lz[p];
    }
  }

  // set a leaf to a value (used during build/initialization)
  void set_point(int pos, int value){
    int p = pos + n;
    push_path(p);
    t[p] = value;
    // no lazy on leaf
    p >>= 1;
    while(p){
      t[p] = max(t[p<<1], t[p<<1|1]) + lz[p];
      p >>= 1;
    }
  }
  void range_add(int l, int r, int val){
    l += n; r += n;
    int L = l, R = r;
    push_path(L);push_path(R);
    while(L <= R){
      if(L & 1) apply(L++, val);
      if(!(R & 1)) apply(R--, val);
      L >>= 1; R >>= 1;
    }
    pull(l);pull(r);
  }
  int range_max(int l, int r){
    l += n; r += n;
    push_path(l); push_path(r);
    int res = -inf;
    while(l <= r){
      if(l & 1) res = max(res, t[l++]);
      if(!(r & 1)) res = max(res, t[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};
LazySeg seg(N);

// compute size of subtree and heavy child at adj[u][0]
void dfs_sz(int u , int p = 0){
	sub[u] = 1 , par[u] = p;
	dep[u] = (p == 0) ? 0 : dep[p] + 1;
	int mxv = -1;
	for(auto &x : adj[u]){
    	if(x == p) continue;
    	dfs_sz(x , u);
    	sub[u] += sub[x];
    	if(sub[x] > mxv){
        	mxv = sub[x];
        	swap(x , adj[u][0]);
    	}
	}
}
// compute head , st , en arrays
void dfs_hld(int u , int p = 0){
	st[u] = ++clk;
	if(p == 0) head[u] = u;
	else if(adj[p][0] == u) head[u] = head[p];
	else head[u] = u;
	for(auto &x : adj[u]){
    	if(x == p) continue;
    	dfs_hld(x , u);
	}
	en[u] = clk;
}
int lca(int a , int b){ 
	while(head[a] != head[b]){
    	if(dep[head[a]] > dep[head[b]]) swap(a , b);
    	b = par[head[b]];
	}
	if(dep[a] > dep[b]) swap(a , b);
	return a;
}
// process path query from a to b (excl = whether to exclude lca node)
// write same for path updates
int path_process(int a , int b , bool excl = false){
	int ret = 0;
	while(head[a] != head[b]){
    if(dep[head[a]] > dep[head[b]]) swap(a , b);
    // make the query on range query data structure
    ret = max(ret, seg.range_max(st[head[b]], st[b]));
    b = par[head[b]];
	}

	if(dep[a] > dep[b]) swap(a , b);
  // make the query on range query data structure
  // st[a]  to st[b] on the same chain (excl = whether to exclude lca node)
  ret = max(ret, seg.range_max(st[a] + excl, st[b]));
	return ret;
} // remember chain are consecutive in dfsarr

// dfs_sz(1);
// dfs_hld(1);
// dfsarr[st[i]] = val[i];
// seg.set_point(st[i], val[i]);
// int ans = path_process(u, v, false);

void solve(){

    cin >> n >> q;

    for(int i=1;i<=n;i++) cin >> val[i];

    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_sz(1);
    dfs_hld(1);

    for(int i=1;i<=n;i++){
        dfsarr[st[i]] = val[i];
        seg.set_point(st[i], val[i]);
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, x;
            cin >> u >> x;
            int diff = x - val[u];
            val[u] = x;
            seg.range_add(st[u], st[u], diff);
        }
        else{
            int u, v;
            cin >> u >> v;
            int ans = path_process(u, v, false);
            cout << ans << " ";
        }
    }
}

signed main(){
    Fast_IO()
    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }
}
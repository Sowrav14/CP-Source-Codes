#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// Disjoint Set Union
struct DSU {
    // parent of each node, rank & size of connected components.
    vector<int> par, rnk, sz;
    int c, mx = 1;
    set<int> s;

    // Initialize DSU -  Every node is parent of itself.
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i=1;i<=n;++i)
            par[i] = i;
    }

    // Find parent of a node...
    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }

    // If two node belongs to same set
    bool same(int i, int j) {
        return find(i) == find(j);
    }

    // return size of connected components that belongs with node i
    int get_size(int i) {
        return sz[find(i)];
    }

    // count of connected components & size of maximum Connected Component. 
    pair<int,int> cc_count() {
        return {c, mx};
    }

    // merge two components.
    int merge(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        mx = max(mx, sz[j]);
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

void solve(){

  int n; cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<pair<int,int>> ans;
  for(int i=0;i<n;i++){
    int mn = v[i];
    while(!pq.empty() && pq.top() < v[i]){
      int x = pq.top();
      pq.pop();
      mn = min(mn, x);
      ans.push_back({x, v[i]});
    }
    pq.push(mn);
  }

  cout << (ans.size() == n - 1 ? "Yes" : "No") << endl;
  // if(ans.size() != n - 1) return;
  // for(auto &it : ans){
  //   cout << it.first << " " << it.second << endl;
  // }

}


signed main(){
  Fast_IO()
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}
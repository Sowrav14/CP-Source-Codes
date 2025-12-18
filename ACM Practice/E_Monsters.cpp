// /**
//  * Cartesian Tree from General Graph
//  * Editorial: https://codeforces.com/blog/entry/114607
//  * Problem: https://codeforces.com/contest/1810/problem/E
//  */
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define endl "\n" 
// const int N = 2e5 + 10;
// const int M = 1e9 + 7;
// const int inf = 1e12;


// // Disjoint Set Union
// struct DSU {
//     // parent of each node, rank & size of connected components.
//     vector<int> par, rnk, sz;
//     int c, mx = 1;

//     // Initialize DSU -  Every node is parent of itself.
//     DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
//         for (int i=1;i<=n;++i)
//             par[i] = i;
//     }

//     // Find parent of a node...
//     int find(int i) {
//         return (par[i] == i ? i : (par[i] = find(par[i])));
//     }

//     // If two node belongs to same set
//     bool same(int i, int j) {
//         return find(i) == find(j);
//     }

//     // return size of connected components that belongs with node i
//     int get_size(int i) {
//         return sz[find(i)];
//     }

//     // count of connected components & size of maximum Connected Component. 
//     pair<int,int> cc_count() {
//         return {c, mx};
//     }

//     // merge two components.
//     int merge(int i, int j) {
//         if ((i = find(i)) == (j = find(j))) return -1;
//         else --c;
//         // if (rnk[i] > rnk[j]) swap(i, j);
//         par[j] = i;
//         sz[i] += sz[j];
//         mx = max(mx, sz[i]);
//         // if (rnk[i] == rnk[j]) rnk[j]++;
//         return i;
//     }
// };

// void solve(){

// 	int n, m; cin >> n >> m;
// 	vector<vector<int>> g(n+1);
// 	vector<int> val(n+1);

// 	for(int i=1;i<=n;i++) cin >> val[i];
// 	for(int i=0;i<m;i++){
// 		int u, v; cin >> u >> v;
// 		g[u].push_back(v);
// 		g[v].push_back(u);
// 	}

// 	vector<int> order(n);
// 	for(int i=0;i<n;i++) order[i] = i+1;
// 	sort(order.begin(), order.end(), [&](int a, int b){
// 		return val[a] < val[b];
// 	});
// 	DSU dsu(n);
// 	vector<vector<int>> tree(n+1);
// 	vector<bool> vis(n+1, false);

// 	for(int u : order){
// 		vis[u] = true;
// 		for(int v : g[u]){
// 			if(!vis[v]) continue;
// 			int pu = dsu.find(u);
// 			int pv = dsu.find(v);
// 			if(pu == pv) continue;
// 			int p = dsu.merge(u, v);
// 			// cout << "Merged " << u << " and " << v << " with parent " << p << endl;
// 			tree[p].push_back(pv);
// 		} 
// 	}

// 	// for(int i=1;i<=n;i++){
// 	// 	for(int v : tree[i]){
// 	// 		cout << i << " -> " << v << endl;
// 	// 	}
// 	// }

// 	int r = order.back();
// 	vector<int> sub(n+1, 0);
// 	function<bool(int, int)> dfs = [&](int u, int req) -> bool {
// 		sub[u] = 1;
// 		bool f = (val[u] == 0);
// 		for(int v : tree[u]){
// 			f |= dfs(v, val[u]);
// 			sub[u] += sub[v];
// 		}
// 		return (f && sub[u] >= req);
// 	};

// 	if(dfs(r, 0) && sub[r] == n) {
// 		cout << "YES" << endl;
// 	} else {
// 		cout << "NO" << endl;
// 	}

// }


// signed main(){
// 	Fast_IO()
// 	int t = 1;
// 	cin >> t;
// 	for(int i=1;i<=t;i++){
// 			// cout << "Case #" << i << ": ";
// 			solve();
// 	}
// }


#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define testing cout << "testing ";
#define mod 1000000007
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<int>adj[200001];
int vis[200001];
int a[200001];


int color;
int n;
bool bfs(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int u=src;
    pq.push({a[u],u}),vis[u]=color;
    int curr=0;
    int total=0;
    while(!pq.empty()){
        auto [val,u]=pq.top();
        pq.pop();
        if(curr<val) break;

        curr++;
        total++;
        if(total==n) return true;
        for(auto c:adj[u]){
            if(vis[c]==color) continue;
            vis[c]=color;
            pq.push({a[c],c});
        }
    }
    return false;


}

void do_the_honour(){

    int m; cin >> n >> m;


    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) adj[i].clear();



    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color=0;
    for(int i=1;i<=n;i++) {

        if(a[i]!=0 or vis[i]!=0) continue;
        
        color++;
        if(bfs(i)) {yes;return;}

    }
    no;


}

int main(){
    optimize();
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++){


    do_the_honour();


}
    return 0;
}

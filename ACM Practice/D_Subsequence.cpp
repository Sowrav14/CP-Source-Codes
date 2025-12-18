#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 4005;
const long long NEG = (long long)-9e18;

/*
Implementation notes (kept logic identical to provided C code):
- Build min Cartesian tree with a monotonic stack.
- ls[u], rs[u] are left/right child indices.
- lw[u], rw[u] store edge weights to left/right child (difference of values).
- f[u][k] stores maximum value for selecting exactly k elements in subtree u
  (we keep 0..M valid indices).
- DFS merges child DP's with knapsack-like backwards loops.
This version follows the user's template and coding style.
*/

int n, m;
int a[N];
int ls[N], rs[N];
int lw[N], rw[N];
int sz[N];
long long f[N][N];

inline void umax(long long &x, long long y){
    if(y > x) x = y;
}

void dfs(int u){
    sz[u] = 1;
    // initialize: selecting 0 -> 0, selecting 1 (this node) -> 0 (no pairs yet)
    for(int i=0;i<=m;i++) f[u][i] = NEG;
    f[u][0] = 0;
    f[u][1] = 0;

    if(ls[u]){
        dfs(ls[u]);
        int lim_u = min((int)m, sz[u]);
        int lim_l = min((int)m, sz[ls[u]]);
        // use temporary buffer to avoid overwrite during iteration
        static long long tmp[N];
        for(int i=0;i<=min((int)m, sz[u]+sz[ls[u]]); i++) tmp[i] = NEG;
        for(int i=0;i<=lim_u;i++){
            if(f[u][i] == NEG) continue;
            for(int j=0;j<=lim_l;j++){
                if(f[ls[u]][j] == NEG) continue;
                umax(tmp[i + j], f[u][i] + f[ls[u]][j] + (long long) j * (m - j) * (long long)lw[u]);
            }
        }
        sz[u] += sz[ls[u]];
        int newlim = min((int)m, sz[u]);
        for(int i=0;i<=newlim;i++){
            f[u][i] = tmp[i];
        }
    }

    if(rs[u]){
        dfs(rs[u]);
        int lim_u = min((int)m, sz[u]);
        int lim_r = min((int)m, sz[rs[u]]);
        static long long tmp[N];
        for(int i=0;i<=min((int)m, sz[u]+sz[rs[u]]); i++) tmp[i] = NEG;
        for(int i=0;i<=lim_u;i++){
            if(f[u][i] == NEG) continue;
            for(int j=0;j<=lim_r;j++){
                if(f[rs[u]][j] == NEG) continue;
                umax(tmp[i + j], f[u][i] + f[rs[u]][j] + (long long) j * (m - j) * (long long)rw[u]);
            }
        }
        sz[u] += sz[rs[u]];
        int newlim = min((int)m, sz[u]);
        for(int i=0;i<=newlim;i++){
            f[u][i] = tmp[i];
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ls[i] = rs[i] = lw[i] = rw[i] = 0;
        sz[i] = 0;
    }

    vector<int> st; // monotonic stack storing indices
    for(int i=1;i<=n;i++){
        int last = 0;
        // Pop all elements larger than current
        while(!st.empty() && a[st.back()] > a[i]){
            last = st.back();
            st.pop_back();
        }
        if(!st.empty()){
            // Current becomes right child of top of stack
            rs[st.back()] = i;
            rw[st.back()] = a[i] - a[st.back()];
        }
        if(last){
            // Last popped becomes left child of current
            ls[i] = last;
            lw[i] = a[last] - a[i];
        }
        st.push_back(i);
    }

    int root = st[0]; // bottom of stack is root
    dfs(root);

    cout << f[root][m] << endl;
}


signed main(){
    Fast_IO()
    solve();
    return 0;
}

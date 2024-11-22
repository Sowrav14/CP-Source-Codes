#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int c[N];
vector<int>g[N];

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 10) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] += val;
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx) & (-idx);
        }
        return sum;
    }
    // update the value at [l...r] by val.
    void update(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
    // sum form [l...r]
    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int st[N], fi[N];
int timer = 0;
int ara[N];
// dfs for euler tour...
// calculate entering time end leaving time of each node...
/// also relocating the array...
void dfs(int u, int p){
    st[u] = ++timer;
    ara[timer] = c[u];
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }
    fi[u] = timer;
}


int ans[N];
pair<int,int> q[N];

void makeQuery(){
    for(int i=1;i<=n;i++){
        q[st[i]] = {fi[i], i};
    }
}

void queryProcessing(){
    map<int,int>li;
    BIT bit(n);

    for(int i=n;i>=1;i--){
        int color = ara[i];

        if(li.count(color) > 0) bit.update(li[color], -1);
        li[color] = i;
        bit.update(i, 1);

        ans[q[i].second] = bit.query(q[i].first); 
    }
}


void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];

    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    // for(int i=1;i<=n;i++) cout << st[i] << " " << fi[i] << endl;
    // for(int i=1;i<=n;i++) cout << ara[i] << " "; cout << endl;
    makeQuery();
    queryProcessing();
    // for(int i=1;i<=n;i++) cout << q[i].first << " " << q[i].second << endl;

    for(int i=1;i<=n;i++) cout << ans[i] << " \n"[i == n];

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
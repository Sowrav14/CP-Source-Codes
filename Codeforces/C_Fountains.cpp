#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//      <cost, beauty>
vector<pair<int,int>>coins, diamonds, a;


int n, c, d;
const int N = 2e5+10;
int tree[4*N];

void build(int node, int l, int r){
    if(l == r){ 
        tree[node] = a[l].second;
        return;
    }

    int m = (l + r) / 2;
    build(2*node+1, l, m);
    build(2*node+2, m+1, r);
    tree[node] = max(tree[2*node+1], tree[2*node+2]);
}

int query(int node, int l, int r, int i, int j){
    if(l>j or r<i) return 0;
    if(l>=i and r<=j) return tree[node];
    int m = (l + r) / 2;
    return max(query(2*node+1, l, m, i, j), query(2*node+2, m+1, r, i, j));
}

int func(int flag){
    int mxcost;
    if(flag == 1){
        a = coins;
        mxcost = c;
    } else{
        a = diamonds;
        mxcost = d;
    }

    int sz = a.size();
    for(int i=0;i<4*sz;i++) tree[sz] = 0;
    build(0, 0, sz-1);

    int ret = 0;
    for(int i=0;i<sz;i++){
        int cc = a[i].first;
        int cb = a[i].second;

        int left = mxcost - cc;
        pair<int,int> x = {left+1, 0};
        int r = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        if(r < 0) continue;
        int mxb = 0;
        if(i > r){
            mxb = max(mxb, query(0, 0, sz-1, 0, max(0ll, r)));
        } else{
            if(i-1 > 0) mxb = max(mxb, query(0, 0, sz-1, 0, i-1));
            mxb = max(mxb, query(0, 0, sz-1, i+1, r));
        }

        // cout << left << " " << i << " " << r << " " << cb << " " <<  mxb << endl;
        ret = max(ret, cb + mxb);
    }
    return ret;
}


void solve(){

    cin >> n >> c >> d;
    int mxb1 = 0, mxb2 = 0;

    for(int i=0;i<n;i++){
        int b, cost;
        char type; 
        cin >> b >> cost >> type;

        if(type == 'C'){
            if(cost > c) continue;
            coins.push_back({cost, b});
            mxb1 = max(mxb1, b);
        } else {
            if(cost > d) continue;
            diamonds.push_back({cost, b});
            mxb2 = max(mxb2, b);
        }
    }
    sort(coins.begin(), coins.end());
    sort(diamonds.begin(), diamonds.end());
    // for(auto i : coins){
    //     cout << i.first << " " << i.second << endl;
    // }

    int ans = 0;
    if(mxb1 != 0 and mxb2 != 0){
        ans = mxb1 + mxb2;
    }
    
    if(coins.size() >= 2) ans = max(func(1), ans);
    if(diamonds.size() >= 2) ans = max(func(2), ans);

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
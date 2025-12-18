#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Solution approach (brief):
- Use binary lifting to jump up to ancestor at depth depth[u]-d.
- Use Heavy-Light Decomposition (HLD) to decompose path from u up to ancestor w into O(log n) contiguous segments on a base array.
- Build a Merge-Sort segment tree over the base array: each seg-tree node stores sorted unique prices, counts for those prices, and prefix sums of counts.
- For a query, decompose the path u->w with HLD into segments [l,r] on base array; for each segment query the merge-sort tree to sum counts for prices within [plower,pupper] using binary search on the sorted price vector and prefix sums.
- Decoding of queries is done online using the previous query answer as described.
*/

int n;
vector<vector<int>> g;
vector<int> parentArr, depthArr, heavy, sz;
vector<int> head, pos, rpos;
int curPos;
int LOG = 20;
vector<vector<int>> up;
vector<int> priceArr;
vector<long long> kArr;

// Merge sort tree storage: unique prices + counts + prefix sums
struct NodeMS {
    vector<int> prices;
    vector<long long> cnts;
    vector<long long> pref;
};
vector<NodeMS> seg;
int segN;

void dfs1(int v,int p){
    parentArr[v]=p;
    up[0][v]= (p==0?0:p);
    depthArr[v] = (p==0?0:depthArr[p]+1);
    sz[v]=1;
    int maxsz=0;
    heavy[v]= -1;
    for(int to: g[v]){
        if(to==p) continue;
        dfs1(to,v);
        if(sz[to]>maxsz){
            maxsz=sz[to];
            heavy[v]=to;
        }
        sz[v]+=sz[to];
    }
}

void dfs2(int v,int h){
    head[v]=h;
    pos[v]=curPos;
    rpos[curPos]=v;
    curPos++;
    if(heavy[v]!=-1){
        dfs2(heavy[v],h);
    }
    for(int to: g[v]){
        if(to==parentArr[v] || to==heavy[v]) continue;
        dfs2(to,to);
    }
}

NodeMS merge_nodes(const NodeMS &A, const NodeMS &B){
    NodeMS R;
    R.prices.reserve(A.prices.size() + B.prices.size());
    R.cnts.reserve(A.prices.size() + B.prices.size());
    size_t i=0,j=0;
    while(i<A.prices.size() && j<B.prices.size()){
        if(A.prices[i] < B.prices[j]){
            R.prices.push_back(A.prices[i]);
            R.cnts.push_back(A.cnts[i]);
            i++;
        } else if(A.prices[i] > B.prices[j]){
            R.prices.push_back(B.prices[j]);
            R.cnts.push_back(B.cnts[j]);
            j++;
        } else {
            R.prices.push_back(A.prices[i]);
            R.cnts.push_back(A.cnts[i] + B.cnts[j]);
            i++; j++;
        }
    }
    while(i<A.prices.size()){
        R.prices.push_back(A.prices[i]);
        R.cnts.push_back(A.cnts[i]);
        i++;
    }
    while(j<B.prices.size()){
        R.prices.push_back(B.prices[j]);
        R.cnts.push_back(B.cnts[j]);
        j++;
    }
    // build prefix sums
    R.pref.resize(R.cnts.size());
    long long cur=0;
    for(size_t t=0;t<R.cnts.size();t++){
        cur += R.cnts[t];
        R.pref[t] = cur;
    }
    return R;
}

void build_merge(int idx,int l,int r, const vector<pair<int,long long>> &base){
    if(l==r){
        seg[idx].prices.clear();
        seg[idx].cnts.clear();
        seg[idx].pref.clear();
        seg[idx].prices.push_back(base[l].first);
        seg[idx].cnts.push_back(base[l].second);
        seg[idx].pref.push_back(base[l].second);
        return;
    }
    int mid=(l+r)/2;
    build_merge(idx*2,l,mid,base);
    build_merge(idx*2+1,mid+1,r,base);
    seg[idx] = merge_nodes(seg[idx*2], seg[idx*2+1]);
}

long long query_merge(int idx,int l,int r,int ql,int qr,int pl,int pu){
    if(qr<l || r<ql) return 0;
    if(ql<=l && r<=qr){
        auto &vec = seg[idx].prices;
        if(vec.empty()) return 0;
        auto &pref = seg[idx].pref;
        auto itl = lower_bound(vec.begin(),vec.end(),pl);
        auto itr = upper_bound(vec.begin(),vec.end(),pu);
        if(itl==vec.end() || itl>=itr) return 0;
        int Lidx = int(itl - vec.begin());
        int Ridx = int(itr - vec.begin()) - 1;
        long long res = pref[Ridx] - (Lidx?pref[Lidx-1]:0);
        return res;
    }
    int mid=(l+r)/2;
    return query_merge(idx*2,l,mid,ql,qr,pl,pu) + query_merge(idx*2+1,mid+1,r,ql,qr,pl,pu);
}

int lift_k(int v,int k){
    for(int j=0;j<LOG && v!=0;j++){
        if(k & (1<<j)){
            v = up[j][v];
        }
    }
    return v;
}

long long query_path(int u,int v,int pl,int pu){ // v is ancestor of u, query path v..u inclusive
    long long res=0;
    while(head[u] != head[v]){
        res += query_merge(1,0,segN-1,pos[head[u]],pos[u],pl,pu);
        u = parentArr[head[u]];
    }
    // now same head; pos[v] <= pos[u]
    res += query_merge(1,0,segN-1,pos[v],pos[u],pl,pu);
    return res;
}

void solve(){

    cin>>n;
    g.assign(n+1, {});
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    kArr.assign(n+1,0);
    priceArr.assign(n+1,0);
    for(int i=1;i<=n;i++){
        long long ki; int pi;
        cin>>ki>>pi;
        kArr[i]=ki;
        priceArr[i]=pi;
    }
    parentArr.assign(n+1,0);
    depthArr.assign(n+1,0);
    heavy.assign(n+1,-1);
    sz.assign(n+1,0);
    head.assign(n+1,0);
    pos.assign(n+1,0);
    rpos.assign(n+1,0);
    curPos=0;
    LOG = 1;
    while((1<<LOG) <= n) LOG++;
    up.assign(LOG, vector<int>(n+1,0));
    dfs1(1,0);
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            int mid = up[j-1][i];
            up[j][i] = (mid==0?0:up[j-1][mid]);
        }
    }
    dfs2(1,1);
    segN = n;
    vector<pair<int,long long>> base(segN);
    for(int i=0;i<segN;i++){
        int node = rpos[i];
        base[i] = { priceArr[node], kArr[node] };
    }
    seg.assign(4*segN+5, NodeMS());
    build_merge(1,0,segN-1,base);

    int q;cin>>q;
    long long ans=0;
    for(int i=0;i<q;i++){
        long long Ui,Di,PLi,PUi;
        cin>>Ui>>Di>>PLi>>PUi;
        int u = (int)((Ui + ans - 1) % n) + 1;
        int d = (int)((Di + ans) % n); // careful: original used (Di + ansi-1) mod n, but statement is (Di + ansi-1) mod n. we kept consistent with previous: (Di+ans-1)%n
        // However to match statement exactly:
        d = (int)((Di + ans - 1) % n);
        int plower = (int)((PLi + ans - 1) % 1000000000) + 1;
        int pupper = (int)((PUi + ans - 1) % 1000000000) + 1;
        if(plower > pupper) swap(plower,pupper);
        int targetDepth = depthArr[u] - d;
        if(targetDepth < 0) targetDepth = 0;
        int diff = depthArr[u] - targetDepth;
        int w = lift_k(u, diff);
        if(w==0) w = 1;
        long long res = query_path(u,w,plower,pupper);
        cout<<res<<"\n";
        ans = res;
    }
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

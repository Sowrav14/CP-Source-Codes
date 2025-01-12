#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 30000 + 10;
const int MAX = 1e6+10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int a[N];
int pre[N];
int oc[MAX];
vector<int> indices[N];


struct PST {
    #define lc t[cur].l
    #define rc t[cur].r

    // defining node for segment tree...
    struct node {
        int l = 0, r = 0, val = 0;
    } t[40 * N];
    // arrays to store given values and roots of each version of st.
    int root[N];

    // initialized without values. return root[0]
    // OR 
    //with values from arr (array). return root[1]
    int T = 0;
    int build(int b, int e) {
        int cur = ++T;
        if (b == e){
            t[cur].val = 0;
            return cur;
        }
        int mid = b + e >> 1;
        lc = build(b, mid);
        rc = build(mid + 1, e);
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }

    // update single value in cur version of st with creating and returning new version.
    int p_update(int pre, int b, int e, int i, int v){
        int cur = ++T;
        t[cur] = t[pre];
        if (b == e){
            t[cur].val += v;        // add.
            return cur;
        }

        int mid = b + e >> 1;
        if (i <= mid){
            rc = t[pre].r;
            lc = p_update(t[pre].l, b, mid, i, v);
        } else {
            lc = t[pre].l;
            rc = p_update(t[pre].r, mid + 1, e, i, v);
        }
        t[cur].val = t[lc].val + t[rc].val;
        return cur;
    }

    // get sum of (i->j) in the cur version 
    int query_sum(int cur, int b, int e, int i, int j){
        if(e < i or b > j) return 0;
        if(b>=i and e<=j) return t[cur].val;

        int m = (b + e) / 2;
        int left = query_sum(t[cur].l, b, m, i, j);
        int right = query_sum(t[cur].r, m+1, e, i, j);
        return left + right;
    }
} pst;

/*

    array = [ 1, 2, 3, 3, 4, 3, 2, 5, 6, 7]
    prev =  [ 0, 0, 0, 3, 0, 4, 2, 0, 0, 0]

    sort the prev array keeping the intial indices.
    prev =  [ 0, 0, 0, 0, 0, 0, 0, 2, 3, 4]
    index = [ 1, 2, 3, 5, 8, 9, 10, 7, 4, 6]

    now build the pst 
        - root[i] = version of st where value till prev[x] <= i 
        are added with their index as 1.
        i.e. 
            root[0] -> 
                                      [1-10]-7
                      [1-5]-4                              [6-10]-3
              [1-3]-3        [4-5]-1           [6-8]-1             [9-10]-2
        [1-2]-2   [3]-1   [4]-0  [5]-1      [6-7]-0  [8]-1       [9]-1  [10]-1
    [1]-1   [2]-1                         [6]-0   [7]-0

    In query
        - for [l...r] distinct element in this range will be sum of [l...r]
        in root[l-1] version of the pst

*/

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = oc[a[i]];
        oc[a[i]] = i;
    }
    // for(int i=1;i<=n;i++) cout << pre[i] << " \n"[i == n];
    // pre array contains value from range 0 to n - 1
    for(int i=1;i<=n;i++){
        indices[pre[i]].push_back(i);
    }

    // configuring the PST
    pst.root[0] = pst.build(1, n);
    for(int i=0;i<=n;i++){
        if(i != 0) pst.root[i] = pst.root[i-1];
        for(auto id : indices[i]){
            pst.root[i] = pst.p_update(pst.root[i], 1, n, id, 1);
        }
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << pst.query_sum(pst.root[l-1], 1, n, l, r) << endl;
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
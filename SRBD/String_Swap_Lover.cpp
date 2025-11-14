#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
const int N = 2e5 + 10;


struct Node {
    int cnt1, cnt0, sum1, sum0;
    bool lazy;
} seg[4*N];

string s;

Node mergeNode(Node a, Node b){
    Node res;
    res.cnt1 = a.cnt1 + b.cnt1;
    res.cnt0 = a.cnt0 + b.cnt0;
    res.sum1 = a.sum1 + b.sum1;
    res.sum0 = a.sum0 + b.sum0;
    res.lazy = 0;
    return res;
}

void doFlip(int idx){
    swap(seg[idx].cnt1, seg[idx].cnt0);
    swap(seg[idx].sum1, seg[idx].sum0);
    seg[idx].lazy ^= 1;
}

void push(int idx){
    if(seg[idx].lazy){
        doFlip(idx * 2);
        doFlip(idx * 2+1);
        seg[idx].lazy = 0;
    }
}

void build(int idx, int l, int r){
    if(l == r){
        if(s[l - 1] == '1') seg[idx] = {1, 0, l, 0, 0};
        else seg[idx] = {0, 1, 0, l, 0};
        return;
    }
    int mid = (l + r) >> 1;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return;
    if(ql <= l && r <= qr){
        doFlip(idx);
        return;
    }
    push(idx);
    int mid = (l + r) >> 1;
    update(idx * 2, l, mid, ql, qr);
    update(idx * 2 + 1, mid + 1, r, ql, qr);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

void solve(){
    int n; cin >> n;
    cin >> s;
    build(1, 1, n);
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        update(1, 1, n, l, r);
        int k = seg[1].cnt1;
        int ans = seg[1].sum1 - k*(k+1)/2;
        cout << ans << endl;
    }
}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}

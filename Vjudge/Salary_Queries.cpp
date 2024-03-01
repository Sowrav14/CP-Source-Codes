#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;

struct node{
    int mn, mx, cnt;
};
int a[N];
node tree[4*N];

void build(int n, int l, int r){
    if(l == r){
        tree[n].mn = a[l];
        tree[n].mx = a[l];
        tree[n].cnt = 1;
        return;
    }

    int m = (l + r) / 2;
    build(2*n, l, m);
    build(2*n+1, m+1, r);

    tree[n].mn = min(tree[2*n].mn, tree[2*n+1].mn);
    tree[n].mx = max(tree[2*n].mx, tree[2*n+1].mx);
    tree[n].cnt = tree[2*n].cnt + tree[2*n+1].cnt;
}

int query(int n, int l, int r, int a, int b){
    int left = tree[n].mn;
    int right = tree[n].mx;
    int occ = tree[n].cnt;

    if(left > b or right < a){
        return 0;
    }
    if(left >= a and right <= b){
        return occ;
    }

    int m = (l + r) / 2;
    int x = query(2*n, l, m, a, b);
    int y = query(2*n+1, m+1, r, a, b);
    return x + y;
}

void update(int n, int l, int r, int i, int v){
    if(i>r or i<l) return;
    if(l == r){
        tree[n].mn = v;
        tree[n].mx = v;
        tree[n].cnt = 1;
        return;
    }
    int m = (l + r) / 2;
    update(2*n, l, m, i, v);
    update(2*n+1, m+1, r, i, v);
    tree[n].mn = min(tree[2*n].mn, tree[2*n+1].mn);
    tree[n].mx = max(tree[2*n].mx, tree[2*n+1].mx);
    tree[n].cnt = tree[2*n].cnt + tree[2*n+1].cnt;
}

void ptree(){
    for(int i=1;i<15;i++){
        cout << tree[i].mn << " " << tree[i].mx << " " << tree[i].cnt << endl;
    }
}

void solve(){

    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    // ptree();

    for(int i=1;i<=q;i++){
        char ch; cin >> ch;
        int a,b; cin >> a >> b;
        if(ch == '?'){
            cout << query(1, 1, n, a, b) << endl;
        } else {
            update(1, 1, n, a, b);
        }
    }

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
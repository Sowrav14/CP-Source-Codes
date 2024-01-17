#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int tree[4*N];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}
    
void update(int node, int l, int r, int i){
    if(l == r){
        if(a[i] == 0){
            a[i] = 1;
            tree[node] = 1;
        }
        else{
            a[i] = 0;
            tree[node] = 0;
        }
        return;
    }
    int m = (l + r) / 2;
    if(i <= m) update(2*node, l, m, i);
    else update(2*node+1, m+1, r, i);
    tree[node] = tree[2*node] + tree[2*node+1];
}
    
int query(int node, int l, int r, int i){
    if(l == r) return l;
    
    int m = (l + r) / 2;
    if(i < tree[2*node]) return query(2*node, l, m, i);
    else return query(2*node+1, m+1, r, i-tree[2*node]);
}



int main(){
    int n; cin >> n;
    int q; cin >> q;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build(1, 0, n-1);
    for(int i=0;i<q;i++){
        int t, idx; cin >> t >> idx;
        if(t == 1){
            update(1, 0, n-1, idx);
        } else {
            cout << query(1, 0, n-1, idx) << endl;
        }
    }

}
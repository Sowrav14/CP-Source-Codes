/*
 * @file test4.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-25
 * @copyright Copyright (c) 2024
 * @problem:    count number of distinct element in a subarray [l...r]
 * @approach:   segment tree (merge sort tree)
 * @explanation:
 */


#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
int a[N];
set<int> tree[N];


void build(int node, int l, int r){
    if(l == r){
        tree[node].insert(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node, m+1, r);
    set<int>t;
    t = tree[2*node];
    t.insert(tree[2*node+1].begin(), tree[2*node+1].end());
    tree[node] = t;
}


int query(int node, int l, int r, int i, int j){
    if(l > j or r < i) return 0;
    if(l>=i and r<=j){
        return tree[node].size;
    }
    int m = (l + r) / 2;
    int left = quer
}

void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    build(1, 1, n);
    cout << tree[1].size() << endl;

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
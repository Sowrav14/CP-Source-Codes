/*
 * @file K_query.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-26
 * @copyright Copyright (c) 2024
 * @problem:
 * @approach:
 * @explanation:
 */


#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 30010;
int a[N];
vector<int> tree[4*N];



void build(int node, int l, int r){
    if(l == r){
        tree[node].push_back(a[l]);
        // cout << a[l] << endl;;
        return;
    }
    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node]));
    return;
    // int i=0, j=0;
    // while(i < tree[2*node].size() and j < tree[2*node+1].size()){
    //     if(tree[2*node][i] < tree[2*node+1][j]){
    //         tree[node].push_back(tree[2*node][i++]);
    //     } else{
    //         tree[node].push_back(tree[2*node+1][j++]);
    //     }
    // }
    // while(i < tree[2*node].size()){
    //     tree[node].push_back(tree[2*node][i++]);
    // }
    // while(j < tree[2*node+1].size()){
    //     tree[node].push_back(tree[2*node+1][j++]);
    // }
}

int query(int node, int l, int r, int i, int j, int k){
    
    if(l>j or r<i){
        return 0;
    }
    if(l>=i and r<=j){
        // int x = tree[node].size();
        // int ll = 0, rr = tree[node].size()-1;
        // while(ll <= rr){
        //     int mm = (ll + rr) / 2;
        //     if(tree[node][mm] > k){
        //         x = mm;
        //         rr = mm - 1;
        //     } else{
        //         ll = mm + 1;
        //     }
        // }
        int x = upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        return tree[node].size() - x;
    }
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j, k);
    int right = query(2*node+1, m+1, r, i, j, k);
    return left + right;
}


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    
    // tree is ok.
    // for(int i=1;i<10;i++){
    //     cout << i << " [ ";
    //     for(auto it : tree[i]) cout << it << " ";
    //     cout << " ]" << endl;
    // }


    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int l, r, k; cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << endl;
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
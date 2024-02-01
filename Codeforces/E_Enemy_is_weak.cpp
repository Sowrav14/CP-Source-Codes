/**
 * @file Enemy_is_week.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2023-10-09
 * @copyright Copyright (c) 2023
 * @problem: find number of lis of length 3.
 * @approach: segment tree.
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6+10;
int st[4*N][3];


void update(int node, int l, int r, int i, vector<int>t){
    if(i > r or i < l) return;
    if(l == r){
        st[node][0] = 1;
        st[node][1] = t[0];
        st[node][2] = t[1];
        return;
    }
    int m = (l + r) / 2;
    update(2*node, l, m, i, t);
    update(2*node+1, m+1, r, i, t);
    st[node][0] = st[2*node][0] + st[2*node+1][0];
    st[node][1] = st[2*node][1] + st[2*node+1][1];
    st[node][2] = st[2*node][2] + st[2*node+1][2];
}

vector<int> query(int node, int l, int r, int i, int j){
    vector<int>t(3, 0);
    if(l>j or r<i){
        return t;
    }
    if(l>=i and r<=j){
        for(int i=0;i<3;i++){
            t[i] = st[node][i];
        }
        return t;
    }
    int m = (l + r) / 2;
    vector<int>left = query(2*node, l, m, i, j);
    vector<int>right = query(2*node+1, m+1, r, i, j);
    for(int i=0;i<3;i++) t[i] = left[i] + right[i];
    return t;
}



void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    reverse(v.begin(), v.end());
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        a.push_back({v[i], i+1});
    }
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        int val = a[i].first;
        int idx = a[i].second;

        vector<int>mx = query(1, 1, n, 0, idx-1);
        update(1, 1, n, idx, mx);
    }

    cout << st[1][2] << endl;

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
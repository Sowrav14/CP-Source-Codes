/*
 * @file Domino_Principle.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-10
 * @copyright Copyright (c) 2024
 * @problem: https://codeforces.com/problemset/problem/56/E
 * @approach: segment tree.
 * @explanation:
 */


/*

    (0, 10), (1, 5), (9, 10), (15, 10)
       4       1       2        1

*/


/*
    In dp approach. dp[i] = how many will fall.
    calculating dp[i]
            iterate through next dominos.
            if (falls) count it and skip the counts iterate remaining next dominos.
            else break.

    traverse from right(reverse sorted).
    array -> 1:(10, 10) 2:(16, 5) 3:(18, 2), 4:(20, 5)
    dp    -> 1: 4       2: 3      3: 1       4: 1
    dp[4] = 1;
    dp[3] = 1 -> in 4 it will not fall break.
    dp[2] = 3 -> in 3 it will fall(add 1) update ptr by 1.
                 in 4 it will fall(add 1) update ptr by 1 (end of bound).
    dp[1] = 4 -> in 2 it will fall(add 3) update ptr by 3 (end of bound).

*/



#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e15;
const int N = 1e5+10;
int tree[4*N];


void update(int node, int l, int r, int i, int val){
    if(l>i or r<i) return;
    if(l == r) {
        tree[node] = val;
        return;
    }
    int m = (l + r) / 2;
    update(2*node, l, m, i, val);
    update(2*node+1, m+1, r, i, val);
    if(tree[2*node] > tree[2*node+1]) tree[node] = tree[2*node];
    else tree[node] = tree[2*node] + tree[2*node+1];
    
}

int query(int node, int l, int r, int i, int j){
    if(l>j or r<i) return 0;
    if(l>=i and r<=j) return tree[node];
    int m = (l + r) / 2;
    int left = query(2*node, l, m, i, j);
    int right = query(2*node+1, m+1, r, i, j);
    if(left > right) return left;
    else return left+right;
}

class dominos{
    public :
        int x,h,id;
        dominos(){
            x = 0;
            h = 0;
            id = 0;
        }
        dominos(int x, int h, int id){
            this->x = x;
            this->h = h;
            this->id = id;
        }
        bool operator < (dominos d){
            return x < d.x;
        }
};

dominos v[N];
int ans[N];


void solve(){

    int n; cin >> n;
    vector<pair<int,int>>a(n+1);
    a[0] = {-inf, -inf};
    for(int i=1;i<=n;i++){
        int x,h; cin >> x >> h;
        v[i] = dominos(x, h, i);
        a[i] = {x, h};
    }
    sort(a.begin(), a.end());
    sort(v+1, v+n+1);

    for(int i=n;i>=1;i--){
        int x = v[i].x;
        int h = v[i].h;
        int idx = v[i].id;
        int next = x + h;
        pair<int,int>p = {next, -inf};
        int it = lower_bound(a.begin(), a.end(), p) - a.begin();
        int mx = query(1, 1, n, i, it-1);
        // cout << idx << " " << x << " " << h << " " << it-1 << " " << mx+1 << endl;
        ans[idx] = mx + 1;
        update(1, 1, n, i, mx+1);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;

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
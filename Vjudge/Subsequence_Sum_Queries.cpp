/*
 * @file Subsequence_Sum_Queries.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2024-02-10
 * @copyright Copyright (c) 2024
 * @problem: https://codeforces.com/gym/101741/problem/J
 * @approach: segment tree.
 * @explanation: for each node we maintain a vector of size m.
 *              in each element of vector will contains how many combination are 
 *              that will ends up with i. v[i] = k means there are k subsequeces
 *              that sum % m = i.
 * 
 * 
 *              m = 3.[mod0, mod2, mod3]
 *                                      [5 1 3 2]
 *                                      [5, 4, 6]
 *                              [5 1]               [3 2]
 *                              [1, 1, 1]            [1, 0, 2]
 *                      [5]         [1]         [3]         [2]
 *                  [0, 0, 1]     [0, 1, 0]   [1, 0, 0]   [0, 0, 1]
 * 
 * 
 *          merging two node...
 *          first add them.
 *          then take the n*n product with cocerning mod.
 *          a = [1, 1, 1]  b = [1, 0, 2], merged = [2, 1, 3] (add)
 *          merged = [3, 1, 5] (b is multiplied by a[0] = [0, 1, 2] = [1, 0, 2])
 *          merged = [5, 2, 5] (b is multiplied by a[1] = [1, 2, 0] = [1, 0, 2])
 *          merged = [5, 4, 6] (b is multiplied by a[2] = [2, 0, 1] = [1, 0, 2])
 * 
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 2*1e5+10;
const int M = 1e9+7;
int n,mod;
vector<int>a;
int tree[4*N][20];


void build(int node, int l, int r){
    if(l == r){
        tree[node][a[l] % mod] = 1;
        return;
    }

    int m = (l + r) / 2;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    // merge.
    for(int ii=0;ii<mod;ii++){
        tree[node][ii] = (tree[2*node][ii] + tree[2*node+1][ii]) % M;
    }
    for(int ii=0;ii<mod;ii++){
        for(int jj=0;jj<mod;jj++){
            int xx = (ii + jj) % mod;
            int add = (tree[2*node][ii] * tree[2*node+1][jj]) % M;
            tree[node][xx] = (tree[node][xx] + add) % M;
        }
    }
    return;
}


vector<int> query(int node, int l, int r, int i, int j){
    vector<int>ret(20, 0);
    if(l>j or r<i) return ret;
    if(l>=i and r<=j){
        for(int ii=0;ii<20;ii++){
            ret[ii] = tree[node][ii];
        }
        return ret;
    }

    int m = (l + r) / 2;
    vector<int> left = query(2*node, l, m, i, j);
    vector<int> right = query(2*node+1, m+1, r, i, j);
    // merge.
    for(int ii=0;ii<mod;ii++){
        ret[ii] = (left[ii] + right[ii]) % M;
    }
    for(int ii=0;ii<mod;ii++){
        for(int jj=0;jj<mod;jj++){
            int x = (ii + jj) % mod;
            int add = (left[ii] * right[jj]) % M;
            ret[x] = (ret[x] + add) % M;
        }
    }
    return ret;
}



void solve(){

    cin >> n >> mod;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    
    build(1, 1, n); 
    // cout << tree[1][0] << endl;
    // for(int i=0;i<3;i++) cout << tree[1][i] << " "; cout << endl;
    // for(int i=0;i<3;i++) cout << tree[2][i] << " "; cout << endl;
    // for(int i=0;i<3;i++) cout << tree[3][i] << " "; cout << endl;
    // int ret[20] = {0};
    // for(int ii=0;ii<20;ii++){
    //     ret[ii] = ad(tree[2][ii], tree[3][ii]);
    // }
    // for(int ii=0;ii<20;ii++){
    //     for(int jj=0;jj<20;jj++){
    //         int x = (ii+jj) % m;
    //         ret[x] = ad(ret[x], gun(tree[2][ii], tree[3][jj]));
    //     }
    // }
    // for(int i=0;i<3;i++) cout << ret[i] << " "; cout << endl;


    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        vector<int>temp = query(1, 1, n, l, r);
        cout << (temp[0] + 1) % M << endl;
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
/**
 * @file C_Subsequences.cpp
 * @author Sowrav Nath
 * @version 0.1
 * @date 2023-10-09
 * @copyright Copyright (c) 2023
 * @problem: find number of lis of length k.
 * @approach: segment tree.
 * @explantion:
 *              use a vector of size k for every node of segment tree.
 *              a node  a[i] is [1, 3, 2] means,
 *                        1 lis of length-1
 *                        3 lis of length-2
 *                        2 lis of length-3.
 *              now if a[j] > a[i] then a[j] will be appended after a[i] so
 *              [1, 1, 3] means 
 *                        1 lis of length-1
 *                        1 lis of length-2
 *                        3 lis of length-3
 *              so go as usual lis by segment tree.
 */



#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define int long long int
#define f1(i,n) for(int i=1;i<=n;i++)
pair<int,int> a[N];
int n,k;
int tree[4*N][12];

void update(int node, int l, int r,int i, vector<int>temp){
    
    if(i>r or i<l) return;
    if(l == r){
        tree[node][0] = 0;
        tree[node][1] = 1;
        for(int k=2;k<=11;k++){
            tree[node][k] = temp[k-1];
        }
        return;
    }

    int mid = (l + r) / 2;
    update(2*node, l, mid, i, temp);
    update(2*node+1, mid+1, r, i, temp);
    // merge(add) left and right...
    for(int k=0;k<=11;k++){
        tree[node][k] = tree[2*node][k] + tree[2*node+1][k];
    }
}

vector<int> query(int node, int l, int r, int i, int j){
    // non relative segment
    if(i>r or j<l){
        vector<int>ret(12, 0);
        return ret;
    }
    if(i<=l and j>=r){
        // return the vector stored in that node
        vector<int>ret(12, 0);
        for(int k=0;k<=11;k++){
            ret[k] = tree[node][k];
        }
        return ret;
    }

    int mid = (l + r) / 2;
    vector<int> left = query(2*node, l, mid, i, j);
    vector<int> right =query(2*node+1, mid+1, r, i, j);
    vector<int>cur(12, 0);
    // merge(add) left and right
    for(int k=0;k<=11;k++){
        cur[k] = left[k] + right[k];
    }
    return cur;
}


signed main(){
    cin >> n >> k;
    f1(i,n){
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a+1, a+n+1);
    
    f1(i,n){
        int val = a[i].first;
        int idx = a[i].second;

        vector<int> mx = query(1, 1, n, 0, idx-1);
        for(auto i : mx) cout << i << " "; cout << endl;
        cout << val << " " << idx << " " << endl;
        update(1, 1, n, idx, mx);
    }

    cout << tree[1][k+1] << endl;

    for(int i=0;i<12;i++){
        cout << tree[1][i] << " ";
    } cout << endl;

}
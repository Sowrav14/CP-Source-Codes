/**
 * @file 12.04 count_inversion_range_query.cpp
 * @author Sowrav Nath
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * @copyright Copyright (c) 2024
 * @problem: Spoj How many lis
 * @apprach: segment tree.
 * @explanation: As usual go with segment tree.
 *              take the array with indices. sort it
 *              for a[i] with index j find max from 0 to j-1
 *              append this with current i.e. lis_len = max_len + 1, ways = max_ways
 *              update this in current index - j.
 *              segment tree contains pair lis_len and lis_ways
 *              merging two node means take the max_len or add them if equal.
 *              In update if current and updating lis is same then add lis_ways
 *              else update the max_lis.
 */             
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define pii pair<int,int>
#define ordered_set tree<int, null_type, less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int mod = 1e9+7;
// ordered_set os;
pii st[4*N];

pii merge(pii a, pii b){
    if(a.first > b.first){
        return a;
    } else if(a.first < b.first){
        return b;
    } else {
        return {a.first, (a.second%mod+b.second%mod)%mod};
    }
}


void update(int node, int l, int r, int i, pii val){
    
    if(i>r or i<l) return;
    if(l == r){
        if(st[node].first == val.first){
            st[node].second += val.second;
            st[node].second %= mod;
        } else {
            st[node] = val;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(2*node, l, mid, i, val);
    update(2*node+1, mid+1, r, i, val);
    st[node] = merge(st[2*node], st[2*node+1]);
}

pii query(int node, int l, int r, int i, int j){
    if(i>r or j<l) return {0,0};
    if(i<=l and j>=r){
        return st[node];
    }

    int mid = (l + r) / 2;
    pii left = query(2*node, l, mid, i, j);
    pii right = query(2*node+1, mid+1, r, i, j);
    return merge(left, right);
}



void solve(){

    int n; cin >> n;
    vector<int>v(n);
    vector<int>temp;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v[i] = x;
        // os.insert(x);
        temp.push_back(x);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    // for(auto i : temp) cout << i << " "; cout << endl;

    for(int i=0;i<n;i++){
        int cur = v[i];
        int idx = lower_bound(temp.begin(), temp.end(), cur) - temp.begin() + 1;
        
        pii mx = query(1, 1, n, 0, idx-1);
        // cout << id << " " << mx.first << " " << mx.second << endl;
        int lis = 1, no = 1;
        if(mx.first+1 > lis){
            lis = mx.first+1;
            no = mx.second;
        }
        update(1, 1, n, idx, {lis, no});
    }

    cout << st[1].first << " " << st[1].second << endl;


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
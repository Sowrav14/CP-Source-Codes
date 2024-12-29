/**
 * @file 12.04 count_inversion_range_query.cpp
 * @author Sowrav Nath
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * @copyright Copyright (c) 2024
 * @problem: Spoj How many lis
 * @apprach: BIT.
 * @explanation: For using bit array we need coordinate compression first..
 *               logic is same when updating a value find max from [1... val-1]
 *               and update max + 1 in val
 *               and last bit[n] will give the answer.
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
ordered_set os;
vector<int>bit;
int n;
// returns maximum [1...idx]
int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret = max(ret, bit[idx]);
        idx -= (idx) & (-idx);
    }
    return ret;
}

// updating in idx means find max [1...idx-1]
// update (max+1) in idx.
void update(int idx){
    int x = query(idx-1);
    while(idx <= n){
        bit[idx] = max(bit[idx], x+1);
        idx += (idx) & (-idx);
    }
}


void solve(){

    cin >> n;
    bit.resize(n+10, 0);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        os.insert(v[i]);
    }
    for(int i=0;i<n;i++){
        v[i] = os.order_of_key(v[i]) + 1;
        update(v[i]);
    }
    cout << query(n) << endl;

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
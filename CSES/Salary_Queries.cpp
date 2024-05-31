/**
 * @file 12.03 count_of_inversion_ordered_set.cpp
 * @author Sowrav Nath
 * @brief 
 * @version 0.1
 * @date 2024-01-22
 * @copyright Copyright (c) 2024
 * @problem:  CSES-Salary_Queries https://cses.fi/problemset/task/1144
 * @approach: Ordered set Method.
 * @explanation:
 *              We will be using the function order_of_key(K) which returns number of elements strictly smaller than K in log N time.
 */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// Ordered Set Tree
#define int long long int
#define ordered_set tree<pair<int,int>, null_type, less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).

void solve(){

    int n, q; cin >> n >> q;
    vector<int>v(n+1);
    ordered_set os;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        os.insert({x, i});
        v[i] = x;
    }
    
    while(q--){
        char t; cin >> t;

        if(t == '?'){
            int a,b; cin >> a >> b;
            int st = os.order_of_key({a, 0});
            int en = os.order_of_key({b, n+1});
            cout << en - st << endl;
        } else{
            int k,x; cin >> k >> x;
            int cur = v[k];
            os.erase(os.find({cur, k}));
            os.insert({x, k});
            v[k] = x;
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
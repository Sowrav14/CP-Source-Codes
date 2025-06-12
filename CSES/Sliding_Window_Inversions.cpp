#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ordered_set<pair<int, int>> os;
    vector<long long int> res;
    long long int inv = 0;

    // Initial window
    for (int i = 0; i < k; ++i) {
        inv += 1ll * (os.size() - os.order_of_key({a[i], i}));
        os.insert({a[i], i});
    }
    res.push_back(inv);

    // Sliding window
    for (int i = k; i < n; ++i) {
        // Remove outgoing element
        os.erase({a[i - k], i - k});
        inv -= os.order_of_key({a[i - k], i - k});
        // Add incoming element
        inv += os.size() - os.order_of_key({a[i], i});
        os.insert({a[i], i});
        res.push_back(inv);
    }

    // Output
    for (auto x : res) cout << x << " ";
    cout << "\n";

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
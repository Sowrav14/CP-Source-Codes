#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

set<int> ls, rs;
int n, m;
vector<int> arr;

void subset_sum(int i, int sum, bool f) {
    if(f){
        if(i == n/2){
            ls.insert(sum);
            return;
        }
    } else {
        if(i == n){
            rs.insert(sum);
            return;
        }
    }
    // Include the current element
    subset_sum(i + 1, (sum%m + arr[i]%m)%m, f);
    // Exclude the current element
    subset_sum(i + 1, sum, f);
}

void solve(){

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    subset_sum(0, 0, true);
    subset_sum(n/2, 0, false);

    // for(auto x : ls) cout << x << " "; cout << endl;
    // for(auto x : rs) cout << x << " "; cout << endl;

    int mx = 0;
    for(auto x : ls) {
        auto it = rs.lower_bound((m - x + m) % m);
        if(it != rs.end()) {
            mx = max(mx, (x + *it) % m);
        }
        if(it != rs.begin()) {
            it--;
            mx = max(mx, (x + *it) % m);
        }
    }
    for(auto x : rs) {
        auto it = ls.lower_bound((m - x + m) % m);
        if(it != ls.end()) {
            mx = max(mx, (x + *it) % m);
        }
        if(it != ls.begin()) {
            it--;
            mx = max(mx, (x + *it) % m);
        }
    }
    cout << mx << endl;

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
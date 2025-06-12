#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int,stack<int>>m;
    for(int i=0;i<n;i++){
        m[a[i]].push(i);
    }

    int end = n - 1;
    int ans = 0;
    while(end >= 0){
        int start = n - 1;
        for (auto it = m.begin(); it != m.end();) {
            int x = it->second.top();
            start = min(start, x);
            // cout << x << " ";
            it->second.pop();
            if (it->second.empty()) {
                it = m.erase(it);
            } else {
                ++it;
            }
        }
        for (auto it = m.begin(); it != m.end();) {
            // int x = it->second.top();
            // start = min(start, x);
            // // cout << x << " ";
            // it->second.pop();
            while(!it->second.empty() and it->second.top() > start) it->second.pop();
            if (it->second.empty()) {
                it = m.erase(it);
            } else {
                ++it;
            }
        }
        // cout << start << " " << end << endl;
        // for(auto i : m) cout << i.first << " " << i.second.size() << endl;
        ans++;
        end = start - 1;
    }
    cout << ans << endl;
    
}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
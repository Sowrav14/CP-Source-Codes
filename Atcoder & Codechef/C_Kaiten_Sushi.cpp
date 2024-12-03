#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<pair<int,int>>a, b;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a.push_back({x, i});
    }
    for(int j=0;j<m;j++){
        int x; cin >> x;
        b.push_back({x, j+1});
    }

    sort(b.begin(), b.end());
    vector<int>ans(m+1, -1);
    int last = m;
    for(int i=0;i<n;i++){
        int x = a[i].first;
        pair<int,int> t = {x, 0};
        int it = lower_bound(b.begin(), b.end(), t) - b.begin();
        // cout << it << endl;

        for(int j=it;j<last;j++){
            ans[b[j].second] = i + 1;
        }
        last = min(last, it);
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << endl;
    }
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
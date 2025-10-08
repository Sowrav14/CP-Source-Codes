#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    int cnt = 0;
    vector<int> v[2];
    // for(int i=0;i<m;i++){
    //     if(a[i] == b[i]) cnt++;

    //     if(b[i] == 0) v[0].push_back(i);
    //     else v[1].push_back(i);
    // }

    for(int i=0;i<n;i++){
        if(i < m) {
            if(b[i] == 0) v[0].push_back(i);
            else v[1].push_back(i);
        }
        int x = i - cnt;
        int p = (a[i] == 1);
        int it = lower_bound(v[p].begin(), v[p].end(), x) - v[p].begin();

        if(it != v[p].size()) cnt++;
    }

    cout << n - cnt << endl;

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
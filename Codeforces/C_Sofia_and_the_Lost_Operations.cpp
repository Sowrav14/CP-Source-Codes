#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    map<int,queue<int>>m;
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        m[b[i]].push(i);
    }
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) m[b[i]].push(i);
    }

    int k; cin >> k;
    for(int i=0;i<k;i++){
        int d; cin >> d;
        if(m[d].empty() and i == k-1) {
            cout << "NO" << endl;
            return;
        } else if(m[d].empty()){
            continue;
        }
        int id = m[d].front();
        m[d].pop();
        a[id] = d;
        m[d].push(id);
    }

    for(int i=0;i<n;i++){
        if(a[i] != b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> v = a;
    sort(v.begin(), v.end());
    int kth = v[k-1];
    vector<int> vis(n, 0);
    for(int i=0;i<n;i++){
        if(a[i] > kth) vis[i] = 1;
    }

    int l = 0, r = n - 1;
    while(l <= r){
        if(vis[l]){
            l++;
            continue;
        }
        if(vis[r]){
            r--;
            continue;
        }
        if(a[l] == a[r]){
            l++, r--;
            continue;
        }

        if(a[l] == kth){
            vis[l] = 1;
            l++;
            continue;
        }
        if(a[r] == kth){
            vis[r] = 1;
            r--;
            continue;
        }
        cout << "NO" << endl;
        return;
    }

    l = 0, r = n - 1;
    int cnt = 0;
    while(l <= r){
        if(vis[l] == 1){
            l++;
            cnt++;
            continue;
        }
        if(vis[r] == 1){
            r--;
            cnt++;
            continue;
        }
        if(a[l] != a[r]){
            cout << "NO" << endl;
            return;
        }
        l++, r--;
    }
    // cout << cnt << endl;
    if(n - cnt < k - 1) cout << "NO" << endl;
    else cout << "YES" << endl;

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
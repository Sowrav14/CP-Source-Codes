#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    set<int> s;
    for(int i=0;i<=n;i++){
        s.insert(i);
    }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int x = a[i];
        if(x <= n){
            mp[x]++;
            if(mp[x] == 1){
                s.erase(x);
            }
        }

        if(i >= k and a[i-k] <= n){
            mp[a[i-k]]--;
            if(mp[a[i-k]] == 0) {
                s.insert(a[i-k]);
            }
        }
        if(i >= k - 1){
            auto it = s.begin();
            cout << *it << " ";
        }
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
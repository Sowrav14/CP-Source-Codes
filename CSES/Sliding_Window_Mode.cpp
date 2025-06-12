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
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> oc;
    map<int, set<int>> freq;

    for(int i=0;i<n;i++){
        if(oc[a[i]]){
            freq[oc[a[i]]].erase(a[i]);
            if(freq[oc[a[i]]].empty()) {
                freq.erase(oc[a[i]]);
            }
        }
        oc[a[i]]++;
        freq[oc[a[i]]].insert(a[i]);

        if(i >= k){
            freq[oc[a[i-k]]].erase(a[i-k]);
            if(freq[oc[a[i-k]]].empty()) {
                freq.erase(oc[a[i-k]]);
            }
            oc[a[i-k]]--;
            if(oc[a[i-k]] == 0) {
                oc.erase(a[i-k]);
            } else {
                freq[oc[a[i-k]]].insert(a[i-k]);
            }
        }
        if(i >= k - 1){
            auto it = freq.rbegin();
            cout << *it->second.begin() << " ";
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
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

    map<int, int> freq;
    for(int i=0;i<n;i++){
        freq[a[i]]++;
        if(i>=k){
            freq[a[i-k]]--;
            if(freq[a[i-k]] == 0) freq.erase(a[i-k]);
        }
        if(i >= k - 1) cout << freq.size() << " ";
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
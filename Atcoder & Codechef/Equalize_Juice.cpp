#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
        
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) return cout << 0 << endl, void();
    
    int minOps = n - 1;

    for (int keep = n; keep >= 1; keep--) {
        for (int start = 0; start <= n - keep; start++) {
            long long sum = 0;
            for (int i = start; i < start + keep; i++) {
                sum += a[i];
            }
            if (sum % keep != 0) continue;
            long long target = sum / keep;
            vector<long long> b(a.begin() + start, a.begin() + start + keep);
            bool possible = true;
            vector<long long> prefix_sum(keep + 1, 0);
            for (int i = 0; i < keep; i++) {
                prefix_sum[i + 1] = prefix_sum[i] + b[i];
            }
            for (int i = 1; i <= keep; i++) {
                if (prefix_sum[i] < target * i) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                int operations = n - keep;
                minOps = min(minOps, operations);
            }
        }
    }
    cout << minOps << endl;

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    vector<int> a(32, 0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        for(int j=0;j<32;j++){
            if(x & (1ll << j)) a[j]++;
        }
    }

    // for(int i=0;i<32;i++) cout << a[i] << " "; cout << endl;
    for(int i=0;i<n;i++){
        int x = 0;
        for(int j=0;j<32;j++){
            if(a[j] > 0) {
                x |= (1ll << j);
                a[j]--;
            }
        }
        v[i] = x;
    }
    for(int i=0;i<n;i++) cout << v[i] << " ";  cout << endl;

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
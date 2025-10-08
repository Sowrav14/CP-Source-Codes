#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    vector<int> s(n+1), d(n+1);
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) d[a[i]] = 1;
        else {
            s[a[i]] = 1;
            s[b[i]] = 1;
        }
    }
    bool flag = false;
    for(int i=0;i<=n+1;i++){
        if(s[i] == 0 and d[i] == 0) return cout << i << endl, void();
        if(s[i] == 1 and d[i] == 0){
            if(flag) return cout << i << endl, void();
            else flag = true;
        }
    }

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }

    map<int,int>m;
    int mx = 0;
    for(int i=0;i<n;i++){
        if(m[a[i]]) mx = max(mx, a[i]);
        m[a[i]]++;
        a[i] = mx;
    }

    for(int i=0;i<n;i++) sum += a[i];
    m.clear();
    mx = 0;
    for(int i=0;i<n;i++){
        if(m[a[i]]) mx = max(mx, a[i]);
        m[a[i]]++;
        a[i] = mx;
    }

    for(int i=0;i<n;i++) sum += (n-i) * a[i];

    cout << sum << endl;

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
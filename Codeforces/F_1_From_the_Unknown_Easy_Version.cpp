#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n = 100000;
    cout << "? " << n << " ";
    for(int i=1;i<=n;i++) cout << 1 << " ";
    cout << endl;
    int p; cin >> p;
    if(p == n){
        cout << "! " << 1 << endl;
        return;
    }
    if(p == 1){
        cout << "! " << n << endl;
        return;
    }
    int l = ceil(n / p);
    int r;
    if(p == 1){
        r = n;
    } else {
        r = ceil(n / (p - 1.0));
    }

    //cout << l << " " << r << endl;
    //if(l == r) r++;
    vector<pair<int, int>> v;
    for(int i=l;i<r;i++){
        v.push_back({i/2, (int)ceil(i/2.0)});
    }
    int m = v.size() * 2;
    cout << "? " << m << " ";
    for(auto it : v){
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;
    int q; cin >> q;

    q -= v.size();

    int ans = v.size() - q - 1;
    cout << "! " << (v[ans].first + v[ans].second) << endl;

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

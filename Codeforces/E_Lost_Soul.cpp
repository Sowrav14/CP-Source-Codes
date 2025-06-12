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
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    if(a[n-1] == b[n-1]){
        cout << n << endl;
        return;
    }

    set<pair<int, int>> low, up;
    low.insert({a[n-1], n-1});
    up.insert({b[n-1], n-1});

    for(int i=n-2;i>=0;i--){
        if(a[i] == b[i]){
            cout << i + 1 << endl;
            return;
        }
        auto it = low.lower_bound({a[i], -1});
        if(it != low.end() && it->first == a[i]){
            cout << i + 1 << endl;
            return;
        }
        it = up.lower_bound({b[i], -1});
        if(it != up.end() && it->first == b[i]){
            cout << i + 1 << endl;
            return;
        }
        low.erase({a[i+1], i+1});
        up.erase({b[i+1], i+1});
        swap(low, up);
        it = low.lower_bound({a[i], -1});
        if(it != low.end() && it->first == a[i]){
            cout << i + 1 << endl;
            return;
        }
        it = up.lower_bound({b[i], -1});
        if(it != up.end() && it->first == b[i]){
            cout << i + 1 << endl;
            return;
        }

        low.insert({a[i], i});
        up.insert({b[i], i});
        up.insert({a[i+1], i+1});
        low.insert({b[i+1], i+1});
    }
    cout << 0 << endl;

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
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
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n-1;i++){
        if(a[i] < a.back()) s.insert(a[i]);
    }

    int cnt = 1, prev = a[0];
    while(1){
        int x = prev * 2;
        if(x >= a.back()) {
            prev = a.back();
            cnt++;
            break;
        }
        if(s.empty()){
            cout << -1 << endl;
            return;
        }
        auto it = s.upper_bound(x);
        if(it == s.begin()){
            cout << -1 << endl;
            return;
        }
        it--;
        int y = *it;
        if(y == prev) break;
        cnt++;
        // cout << x << " " << y << " " << cnt << endl;
        prev = y;
    }

    if(prev == a.back()) cout << cnt << endl;
    else cout << -1 << endl;

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
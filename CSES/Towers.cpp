#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.end()){
            s.insert(x);
        } else {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;

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
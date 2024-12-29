#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    set<int>l;
    l.insert(0); l.insert(n);
    multiset<int>d;
    d.insert(n);

    while(k--){
        int x; cin >> x;
        auto it = l.upper_bound(x);
        auto itt = it; itt--;

        d.erase(d.find(*it - *itt));
        d.insert(*it - x);
        d.insert(x - *itt);

        l.insert(x);

        auto ans = d.end();
        ans--;
        cout << *ans << " ";
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
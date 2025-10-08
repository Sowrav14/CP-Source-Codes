#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    multiset<pair<int,int>> ms;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        ms.insert({x, i});
    }
    for(int i=1;i<=k;i++){
        int x; cin >> x;
        pair<int,int> t = {x, 0};
        auto it = ms.lower_bound(t);
        if(it == ms.end()){
            continue;
        }
        if(it->first != x) continue;
        ms.erase(it);
    }
    for(auto i : ms){
        cout << i.first << " ";
    } cout << endl;

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
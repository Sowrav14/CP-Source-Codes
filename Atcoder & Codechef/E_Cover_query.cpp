#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, q; cin >> n >> q;

  set<pair<int,int>> s;
  int black = 0;

  while(q--){
    int l, r;  cin >> l >> r;
    int nl = l, nr = r;

    auto it = s.lower_bound({l, -inf});

    if(it != s.begin()){
        auto p = prev(it);
        if(p->second >= l){
            nl = min(nl, p->first);
            nr = max(nr, p->second);
            black -= (p->second - p->first + 1);
            s.erase(p);
        }
    }

    while(it != s.end() && it->first <= nr){
        nl = min(nl, it->first);
        nr = max(nr, it->second);
        black -= (it->second - it->first + 1);
        it = s.erase(it);
    }

    s.insert({nl, nr});
    black += (nr - nl + 1);

    cout << (n - black) << endl;
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

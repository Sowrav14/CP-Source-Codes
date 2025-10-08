#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Mood {
    int p, a, b;
    Mood(int p, int a, int b) : p(p), a(a), b(b) {}
};

void solve(){

    int n; cin >> n;
    vector<Mood> v;
    for(int i=0;i<n;i++){
        int p, a, b; cin >> p >> a >> b;
        v.push_back(Mood(p, a, b));
    }
    bool flag = 0;
    auto calc = [&](int x) -> int {
        for(int i=0;i<n;i++){
            int t = 0;
            if(v[i].p >= x) x += v[i].a;
            else x -= v[i].b;
            x = max(x, 0ll);
        }
        return x;
    };

    vector<int> ans(10001);
    for(int i=0;i<10001;i++){
        int x = calc(i);
        ans[i] = x;
    }
    
    // for(int i=1;i<=1000;i++) cout << ans[i] << endl;
    
    int q; cin >> q;
    // cout << last << endl;
    int last = 10000;
    while(q--){
        int x; cin >> x;
        if(x <= last) cout << ans[x] << endl;
        else {
            cout << x - last + ans[last]  << endl;
        }
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
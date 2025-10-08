#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;




void solve(){

    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int n; cin >> n;
    int a, b; cin >> a >> b;

    vector<pair<int, char>> ao, to;
    for(int i=0;i<a;i++) {
        char c; cin >> c;
        int x; cin >> x;
        ao.push_back({x, c});
    }
    for(int i=0;i<b;i++){
        char c; cin >> c;
        int x; cin >> x;
        to.push_back({x, c});
    }
    function<pair<int,int>(char)> movv = [&](char c) -> pair<int,int> {
        if(c == 'U') return {-1, 0};
        if(c == 'D') return {1, 0};
        if(c == 'L') return {0, -1};
        return {0, 1};
    };

    int i = 0, j = 0;
    int aoo = ao[0].first;
    int too = to[0].first;
    pair<int,int> pa = movv(ao[0].second);
    pair<int,int> pb = movv(to[0].second);
    int ans = 0;

    while(i<a and j<b){
        int sz = min(aoo, too);
        
        int dr = pa.first - pb.first;
        int dc = pa.second - pb.second;

        int dx = xa - xb;
        int dy = ya - yb;

        if(dr == 0 and dc == 0){
            if(dx == 0 and dy == 0) ans += sz;
        } else {
            if(dr == 0){
                if(dx == 0 and dy%dc == 0) {
                    int k = -dy / dc;
                    if(k >= 1 and k <= sz) ans++;
                }
            } else if(dc == 0){
                if(dy == 0 and dx % dr == 0){
                    int k = -dx / dr;
                    if(k >= 1 and k <= sz) ans++;
                }
            } else{
                if(dx % dr == 0 and dy % dc == 0){
                    int k1 = -dx / dr, k2 = -dy / dc;
                    if(k1 == k2 and k1 >= 1 and k1 <= sz) ans++;
                }
            }
        }
        xa += pa.first * sz;
        ya += pa.second * sz;
        xb += pb.first * sz;
        yb += pb.second * sz;

        aoo -= sz;
        too -= sz;

        if(aoo == 0){
            i++;
            if(i < a){
                aoo = ao[i].first;
                pa = movv(ao[i].second);
            }
        }

        if(too == 0){
            j++;
            if(j < b){
                too = to[j].first;
                pb = movv(to[j].second);
            }
        }
    }
    cout << ans << endl;

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
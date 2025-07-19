#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct casino {
    int l, r, c;
    casino(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}
};

void solve(){

    int n, k; cin >> n >> k;
    vector<casino> v;
    for(int i=0;i<n;i++){
        int l, r, c; cin >> l >> r >> c;
        v.push_back(casino(l, r, c));
    }
    sort(v.begin(), v.end(), [](const casino& a, const casino& b) {
        return a.l < b.l;
    });

    vector<bool> vis(n, 0);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(k);
    int mx = k;
    int i = 0;

    while(!q.empty()){
        int x = q.top(); q.pop();
        while(i < n && v[i].l <= x){
            if(!vis[i] && v[i].r >= x){
                vis[i] = true;
                q.push(v[i].c);
                mx = max(mx, v[i].c);
            }
            i++;
        }
    }
    cout << mx << endl;

}

signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve();
    }
}

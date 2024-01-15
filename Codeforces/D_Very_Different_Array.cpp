#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int n,m; cin >> n >> m;
    deque<int>a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector<int>res;
    while(res.size() < n){
        if(abs(b.back() - a.back()) > abs(b.front() - a.front())){
            res.push_back(abs(b.back() - a.back()));
            b.pop_back(); a.pop_back();
        } else{
            res.push_back(abs(b.front() - a.front()));
            a.pop_front(); b.pop_front();
        }
    }
    int ans = 0;
    for(auto i : res) ans += i;
    cout << ans << endl;

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
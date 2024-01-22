#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<pair<int,int>>v;
int n;

bool check(int m){

    vector<int>less, more;
    for(int i=0;i<n;i++){
        if(v[i].first < m){
            less.push_back(v[i].second);
        } else {
            more.push_back(v[i].first + v[i].second - m);
        }
    }
    sort(less.begin(), less.end());
    sort(more.begin(), more.end());

    if(less.size() > more.size()) return false;
    while(less.size() != 0){
        if(less.back() > more.back()) return false;
        less.pop_back();
        more.pop_back();
    }
    return true;

}

void solve(){

    cin >> n;
    v.clear();
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    int ans = 0;
    int l = 0, r = 1e12;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
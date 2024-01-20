#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second != b.second){
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}



void solve(){

    int n; cin >> n;
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
    int ans = 0;
    int l = 0, r = 1e12;
    while(l <= r){
        int m = (l + r) / 2;

        vector<pair<int,int>>less, more;
        for(int i=0;i<n;i++){
            if(v[i].first < m){
                less.push_back(v[i]);
            } else {
                more.push_back(v[i]);
            }
        }
        sort(less.begin(), less.end(), cmp);
        sort(more.begin(), more.end(), cmp);

        if(less.size() == 0){
            ans = m;
            l = m + 1;
            continue;
        }

        for(int i=0;i<less.size();i++){
            int wt = less[i].second;
        }
    }
    

    

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
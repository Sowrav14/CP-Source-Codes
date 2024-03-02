#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    priority_queue<pair<int,int>>pq;
    queue<pair<int,int>>q;
    int cur; cin >> cur;
    q.push({cur, 1});
    for(int i=2;i<=n;i++){
        int x; cin >> x;
        pq.push({x, i});
    }
    vector<pair<int,int>>ans;
    int flag = 1;
    // cout << q.size() << " " << pq.size() << endl;
    while(1){
        if(q.empty()){
            if(!pq.empty()) flag = 0;
            break;
        }
        int v = q.front().first;
        int i = q.front().second;
        q.pop();
        while(v-- and !pq.empty()){
            // if(pq.empty()) break;;
            int val = pq.top().first;
            int id = pq.top().second;
            pq.pop();
            // cout << i << " " << id << endl;
            ans.push_back({i, id});
            q.push({val, id});
        }
    }

    if(flag){
        cout << ans.size() << endl;
        for(auto i : ans) cout << i.first << " " << i.second << endl;
    } else{
        cout << -1 << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
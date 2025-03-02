#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, x; cin >> n >> x;

    queue<int>q;
    q.push(x);
    map<int,int>d;
    d[x] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        string s = to_string(u);

        if(s.size() == n){
            cout << d[u] << endl;
            return;
        }

        for(char c : s){
            if(c == '0') continue;
            int v = u * (c - '0');
            if(d.find(v) == d.end()){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    cout << -1  << endl;

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m, q; cin >> n >> m >> q;
    vector<int> line(n), slide(m);
    for(int i=0;i<n;i++) cin >> line[i];
    for(int i=0;i<m;i++) cin >> slide[i];

    int i = 0, j = 0;
    vector<int>vis(n+1, 0);
    while(i<n and j<m){
        // cout << i << " --- " << j << endl;
        if(line[i] != slide[j] and !vis[slide[j]]) {
            cout << "TIDAK" << endl;
            return;
        }
        while(j<m and ((line[i] == slide[j]) or vis[slide[j]])){
            // cout << i << " " << j << endl;
            j++;
        }
        vis[line[i]] = 1;
        i++;
    }
    cout << "YA" << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
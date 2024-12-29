#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin >> v[i];
        m[v[i]] = i + 1;
    }
    int i = 1;
    for(auto &it : m){
        it.second = i;
        i++;
    }
    vector<int> pos(n+1);
    for(int i=0;i<n;i++){
        int x = v[i];
        int y = m[x];
        pos[y] = i + 1;
    }

    int ans = 1;
    for(int i=1;i<n;i++){
        if(abs(pos[i+1] - pos[i]) != 1) ans++;
    }
    cout << ans << endl;

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
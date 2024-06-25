#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n,m; cin >> n >> m;
    string a,b; cin >> a;
    vector<int>v(m);
    for(int i=0;i<m;i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<char>c;
    cin >> b;
    for(int i=0;i<m;i++){
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());

    for(int i=0;i<v.size();i++){
        int id = v[i];
        a[id] = c[i];
    }

    cout << a << endl;

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
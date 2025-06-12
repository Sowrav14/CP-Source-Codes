#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int same = 0, flag = 1, pos = -1;
    vector<pair<int,int>> mapping(n+1, {-1, -1});
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            same++;
            pos = i;
            mapping[a[i]] = {b[i], i};
            mapping[b[i]] = {a[i], i};
        } else {
            if(mapping[a[i]].first == -1){
                mapping[a[i]] = {b[i], i};
                mapping[b[i]] = {a[i], -1};
            }
            else if(mapping[a[i]].first != b[i]){
                cout << -1 << endl;
                return;
            } else{
                mapping[a[i]] = {b[i], i};
            }
        }
    }
    if(n%2 == 0 and same){
        cout << -1 << endl;
        return;
    }
    if(n%2 and same != 1){
        cout << -1 << endl;
        return;
    }

    // for(int i=1;i<=n;i++) cout << mapping[i].first << " " << mapping[i].second << endl;
    vector<pair<int,int>> ans;
    if(n%2 and pos != n/2){
        ans.push_back({pos, n/2});
        mapping[a[n/2]] = {b[n/2], pos};
        mapping[b[pos]] = {a[pos], n/2};
        swap(a[pos], a[n/2]);
        swap(b[pos], b[n/2]);
    }

    for(int i=0;i<n/2;i++){
        int j = n-i-1;
        int x = mapping[b[i]].second;
        if(x != j){
            ans.push_back({x, j});
            mapping[a[j]] = {b[j], x};
            mapping[b[i]] = {a[i], j};
            swap(a[x], a[j]);
            swap(b[x], b[j]);
        }
    }

    cout << ans.size() << endl;
    for(auto [x, y] : ans){
        cout << x+1 << " " << y+1 << endl;
    }

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
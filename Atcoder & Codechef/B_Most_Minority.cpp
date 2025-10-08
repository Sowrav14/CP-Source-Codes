#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, m; cin >> n >> m;
    vector<int> a(n, 0);
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int cnt0 = 0, cnt1 = 0;
        for(int j=0;j<n;j++){
            if(v[j][i] == '0') cnt0++;
            else cnt1++;
        }

        if(cnt0 == 0 or cnt1 == 0){
            for(int j=0;j<n;j++){
                a[j]++;
            }
        } else if(cnt0 < cnt1){
            for(int j=0;j<n;j++){
                if(v[j][i] == '0') a[j]++;
            }
        } else {
            for(int j=0;j<n;j++){
                if(v[j][i] == '1') a[j]++;
            }
        }
    }

    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(mx, a[i]);
    }

    for(int i=0;i<n;i++){
        // cout << a[i] << " ";
        if(a[i] == mx){
            cout << i + 1 << " ";
        }
    }
    cout << endl;

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
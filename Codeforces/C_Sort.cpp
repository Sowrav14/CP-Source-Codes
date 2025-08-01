#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<vector<int>> oca(n, vector<int>(26, 0)), ocb(n, vector<int>(26, 0));

    for(int i=0;i<n;i++){
        oca[i][a[i]-'a']++;
        ocb[i][b[i]-'a']++;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++){
            oca[i][j] += oca[i-1][j];
            ocb[i][j] += ocb[i-1][j];
        }
    }

    while(q--){
        int l, r; cin >> l >> r; l--, r--;

        int ans = 0;
        for(int i=0;i<26;i++){
            int ina = oca[r][i] - (l>0 ? oca[l-1][i] : 0);
            int inb = ocb[r][i] - (l>0 ? ocb[l-1][i] : 0);

            ans += abs(ina - inb);
        }
        cout << ans/2 << endl;
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
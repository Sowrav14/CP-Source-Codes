#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    string s; cin >> s;
    int n = s.size();
    vector<int> a(n+1), p(n+2, 0);
    for(int i=1;i<=n;i++){
        if(s[i-1] == '0') a[i] = -1;
        else a[i] = 1;

        p[i] = p[i-1] + a[i];
    }

    // now i have to calculate sum of such indices j where p[i] == p[j] and j > i
    // for every i.
    
    vector<vector<int>> sum(2*n+10);
    for(int i=0;i<=n;i++) sum[p[i]+n].push_back(i);

    // now sum array sum[i] defined the indices where sum == i

    int ans = 0;
    for(int i=0;i<=2*n+2;i++){
        if(sum[i].size() == 0) continue;
        int ys = 0;
        for(int j=sum[i].size()-1;j>=0;j--){
            int x = sum[i][j];
            // contribution = (x + 1) * sumof(n - ys + 1)
            // number of ys * (n + 1) - sum of ys
            int nn = sum[i].size() - j - 1;
            int res = (nn%M * (n + 1)%M)%M;
            res = (res%M - ys%M + M)%M;
            res = (res%M * (x + 1)%M)%M;
            ans = (ans%M + res%M)%M;
            // cout << x << " " << res << endl;
            ys = (ys%M + sum[i][j]%M)%M;
        }
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
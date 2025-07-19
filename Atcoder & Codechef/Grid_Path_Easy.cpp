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

    vector<int> az(n+1, 0), azp(n+1, 0), ao(n+1, 0), aop(n+1, 0);
    for(int i=1;i<=n;i++){
        az[i] = az[i-1];
        ao[i] = ao[i-1];
        azp[i] = azp[i-1];
        aop[i] = aop[i-1];
        if(a[i-1] == '0'){
            az[i] += 1;
            azp[i] += i;
        } else {
            ao[i] += 1;
            aop[i] += i;
        }
    }

    reverse(b.begin(), b.end());
    vector<int> bz(n+1, 0), bzp(n+1, 0), bo(n+1, 0), bop(n+1, 0);
    for(int i=1;i<=n;i++){
        bz[i] = bz[i-1];
        bo[i] = bo[i-1];
        bzp[i] = bzp[i-1];
        bop[i] = bop[i-1];
        if(b[i-1] == '0'){
            bz[i] += 1;
            bzp[i] += i;
        } else {
            bo[i] += 1;
            bop[i] += i;
        }
    }

    vector<int> ac(n+1, -1);
    for(int i=1;i<=n;i++){
        int req = az[i];
        int x = req + ao[i];
        int y = lower_bound(ao.begin(), ao.end(), x) - ao.begin();
        if(y == ao.size()) continue;
        int cost = aop[y] - aop[i] - azp[i];
        ac[i] = cost;
        // cout << i << " " << req << " " << x << " " << y << " " << cost << endl;
        // cout << aop[y] << " " << aop[i] << " " << azp[i] << endl;
    }

    vector<int> bc(n+1, -1);
    for(int i=1;i<=n;i++){
        int req = bz[i];
        int x = req + bo[i];
        int y = lower_bound(bo.begin(), bo.end(), x) - bo.begin();
        if(y == bo.size()) continue;
        int cost = bop[y] - bop[i] - bzp[i];
        bc[i] = cost;
        // cout << i << " " << req << " " << x << " " << y << " " << cost << endl;
        // cout << aop[y] << " " << aop[i] << " " << azp[i] << endl;
    }
    
    int ans = inf;
    for(int i=1;i<=n;i++){
        int x = ac[i];
        int y = bc[n - i + 1];
        if(x == -1 or y == -1) continue;\
        ans = min(ans, x + y);
        // cout << i << " " << x << " " << y << endl;
    }
    if(ans == inf){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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
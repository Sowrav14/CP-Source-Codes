#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2000 + 10;
const int M = 1e9 + 7;
const int inf = 1e18;
int n, m, a, b;
int grid[N][N];
int pref[N][N];
int cnt[N][N];

void prefix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[i][j] = grid[i][j] == -1;
        }
    }

    for(int i=1;i<=n;i++){
        pref[i][0] = 0;
        for(int j=1;j<=m;j++){
            pref[i][j] = pref[i][j-1] + grid[i][j];
            cnt[i][j] += cnt[i][j-1];
        }
    }

    for(int j=1;j<=m;j++){
        pref[0][j] = 0;
        for(int i=1;i<=n;i++){
            pref[i][j] += pref[i-1][j];
            cnt[i][j] += cnt[i-1][j];
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << pref[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << cnt[i][j] << " ";
    //     } cout << endl;
    // }
}

int getsum(int i, int j, int l, int r){
    return pref[l][r] - pref[i-1][r] - pref[l][j-1] + pref[i-1][j-1];
}
int getcnt(int i,int j, int l, int r){
    return cnt[l][r] - cnt[i-1][r] - cnt[l][j-1] + cnt[i-1][j-1];
}

void rotate(){
    vector<vector<int>> tgrid;
    for(int j=1;j<=m;j++){
        vector<int>temp;
        for(int i=1;i<=n;i++){
            temp.push_back(grid[i][j]);
        }
        reverse(temp.begin(), temp.end());
        tgrid.push_back(temp);
    }
    for(int j=0;j<tgrid[0].size();j++){
        for(int i=0;i<tgrid.size();i++){
            grid[i+1][j+1] = tgrid[i][j];
        }
    }
    swap(n, m);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << grid[i][j] << " ";
    //     } cout << endl;
    // } cout << endl;
}

int getans(){
    rotate();
    prefix();
    int ans = inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l = i + a - 1;
            int r = j + b - 1;

            if(l > n or r > m) continue;
            int cnt = getcnt(i, j, l, r);
            // cout << i << " " << j << " " << l << " " << r << endl;
            if(cnt > 0) continue;
            int sum = getsum(i, j, l, r);
            ans = min(ans, sum);
        }
    }

    return ans;
}

void solve(){

    cin >> n >> m >> a >> b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> grid[i][j];
        }
    }

    int ans = inf;
    ans = min(ans, getans());
    ans = min(ans, getans());
    ans = min(ans, getans());
    ans = min(ans, getans());

    if(ans >= inf){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

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
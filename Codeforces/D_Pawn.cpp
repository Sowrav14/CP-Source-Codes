#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = -1e12;
int n,m,k;
int grid[110][110];
int dp[110][110][12];


int recur(int i, int j, int r){
    if(j > m or j < 1) return inf;
    if(i == 0){
        if(r == 0) return 0;
        else return inf;
    }
    if(dp[i][j][r] != -1) return dp[i][j][r];


    int rr = (grid[i][j] + r) % k;
    int ans = max(recur(i-1, j+1, rr), recur(i-1, j-1, rr));
    ans += grid[i][j];
    return dp[i][j][r] = ans;
}


void extractor(int i, int j, int r){
    if(i == 1) return;


    int rr = (grid[i][j] + r) % k;
    if(dp[i][j][r] == grid[i][j] + recur(i-1, j-1, rr)){
        cout << "L";
        extractor(i-1, j-1, rr);
    } else {
        cout << "R";
        extractor(i-1, j+1, rr);
    }
}

void reset(){
    for(int ii=1;ii<=n;ii++){
        for(int jj=1;jj<=m;jj++){
            for(int rr=0;rr<12;rr++){
                dp[ii][jj][rr] = -1;
            }
        }
    }
}


void solve(){

    cin >> n >> m >> k;
    k++;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            grid[i][j+1] = s[j] - '0';
        }
    }
    // cout << recur(3, 2, 0) << endl;
    int ans = inf;
    int start = -1;


    for(int i=1;i<=m;i++){
        reset();
        int res = recur(n, i, 0);
        if(res >= ans){
            ans = res;
            start = i;
        }
    }

    if(ans < 0){
        cout << -1 << endl;
        return;
    }
    reset();
    cout << recur(n, start, 0) << endl;
    cout << start << endl;
    extractor(n, start, 0);

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
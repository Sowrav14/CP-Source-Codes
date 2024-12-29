#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1000 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;
double dp[N][N];

double play(int w, int b){
    if(w <= 0) return 0;
    if(b <= 0) return 1;
    int W = w, B = b;
    if(dp[W][B] != -1.0) return dp[W][B];
    // princess turn 
    double win1 = (1.0 * w) / (b + w);
    double continues1 = (1.0 * b) / (b + w);
    b--;
    if(b == 0) return dp[W][B] = win1;
    // dragon turn
    double win2 = 0;
    double continues2 = (1.0 * b) / (b + w);
    b--;
    // jumped mouse
    double white = ((1.0 * w) / (w + b)) * play(w-1, b);
    double black = ((1.0 * b) / (w + b)) * play(w, b-1);

    double win = win1 + continues1 * continues2 * (white + black);
    return dp[W][B] = win;
}


void solve(){

    int w, b; cin >> w >> b;
    for(int i=0;i<=w;i++){
        for(int j=0;j<=b;j++){
            dp[i][j] = -1.0;
        }
    }
    cout << fixed << setprecision(9) << play(w, b) << endl;

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
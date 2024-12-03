#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, p, k;
struct People {
    int a;
    vector<int>pos;
};
vector<People>v;
int dp[N][1<<7];

int teamForm(int i, int mask){
    if(i == n){
        int player = __builtin_popcount(mask);
        if(player == p) return 0;
        else return -inf;
    }
    if(dp[i][mask] != -1) return dp[i][mask];

    int saw = i;
    int player = __builtin_popcount(mask);
    int cheer = saw - player;
    int ans = -inf;

    if(cheer < k){
        // current can be cheerleader or player
        ans = max(ans, v[i].a + teamForm(i+1, mask));   // taken as cheerleader
        for(int pl = 0; pl < p; pl++){
            if(mask & (1ll << pl)) continue;
            int newmask = (mask | (1ll << pl));
            ans = max(ans, v[i].pos[pl] + teamForm(i+1, newmask)); // taken to play at position pl
        }
    } else {
        // current can only be ignored or take as player
        ans = max(ans, teamForm(i+1, mask));
        for(int pl = 0; pl < p; pl++){
            if(mask & (1ll << pl)) continue;
            int newmask = (mask | (1ll << pl));
            ans = max(ans, v[i].pos[pl] + teamForm(i+1, newmask));
        }
    }
    return dp[i][mask] = ans;
}

void solve(){

    cin >> n >> p >> k;
    for(int i=0;i<n;i++){
        People pp;
        int x; cin >> x;
        pp.a = x;
        v.push_back(pp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            int x; cin >> x;
            v[i].pos.push_back(x);
        }
    }
    sort(v.begin(), v.end(), [](People p1, People p2){
        return p1.a > p2.a;
    });

    // store and sort ok
    // for(auto i : v){
    //     cout << i.a << " ";
    //     for(auto j : i.pos){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    memset(dp, -1, sizeof(dp));
    cout << teamForm(0, 0) << endl;

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
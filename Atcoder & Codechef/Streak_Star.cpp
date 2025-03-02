#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int solve2(int it, int x, int n, vector<int>a){
    if(it != -1) a[it] *= x;
    int prev = 0, cur = 0;
    int ans = 0;
    int i = 0;

    while(i < n){
        if(a[i] >= prev){
            cur++;
        } else{
            cur = 1;
        }
        // cout << i << " " << cur << endl;
        prev = a[i];
        i++;
        ans = max(ans, cur);    
    }
    ans = max(ans, cur);
    return ans;
}


void solve(){

    int n, x; cin >> n >> x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = solve2(-1, x, n, a);
    for(int i=0;i<n;i++){
        ans = max(ans, solve2(i, x, n, a));
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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
int a[N][2];


int recur(int i, int j, int f){
    if(i >= n-1) return 0;

    int ans = 0;
    int x = a[i][0], y = a[i][1], z = a[i+1][0];
    int xx = a[i][0], yy = a[i+1][1], zz = a[i+1][0];
    int xxx = a[i][0], yyy = a[i][1], zzz = a[i+1][1];
    int xxxx = a[i][1], yyyy = a[i+1][0], zzzz = a[i+1][1];

    if(j == 0){
        ans = max(ans, xx + yy + zz + recur(i+2, 0, 0));
        ans = max(ans, xx + yy + zz + recur(i+2, 1, 0));
        if(f == 0) ans = max(ans, x + y + z + recur(i+1, 1, 1));
        if(f == 0) ans = max(ans, xxx + yyy + zzz + recur(i+1, 0, 1));
        ans = max(ans, recur(i, 1, 0));
        ans = max(ans, recur(i+1, 0, 0));
        ans = max(ans, recur(i+1, 1, 0));
    } else {
        ans = max(ans, xxxx+yyyy+zzzz+recur(i+2, 0, 0));
        ans = max(ans, xxxx+yyyy+zzzz+recur(i+2, 1, 0));
        if(f == 0) ans = max(ans, x+y+z+recur(i+1, 1, 1));
        if(f == 0) ans = max(ans, xxx+yyy+zzz+recur(i+1, 0, 1));
        ans = max(ans, recur(i+1, 0, 0));
        ans = max(ans, recur(i+1, 1, 0));
    }

    return ans;
}


void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i][0];
    for(int i=1;i<=n;i++) cin >> a[i][1];

    cout << recur(1, 0, 0) << endl;
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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e7;
const int minf = 1e16;

int a[N];
int pre[N], suf[N];
int prec[N], sufc[N];

void solve(){

    int n, k; cin >> n >> k;

    for(int i=0;i<n;i++){
        int x; cin >> x;
        a[x]++;
    }
    prec[0] = a[0];
    for(int i=1;i<=1e6;i++){
        int x = pre[i-1];
        int y = a[i] * i;
        pre[i] = x + y;
        prec[i] = prec[i-1] + a[i];
    }

    for(int i=1000001;i>=0;i--){
        int x = suf[i+1];
        int y = a[i] * i;
        suf[i] = x + y;
        sufc[i] = sufc[i+1] + a[i];
    }

    int ans = minf;
    int kk = 0;
    while(1){

        if(kk >= inf) break;
        int tk = min(kk, 1000000ll);
        int less = pre[tk];
        int gre = suf[tk+1];

        int lc = prec[tk];
        int gc = sufc[tk+1];

        int lcc = lc * kk;
        int gcc = gc * kk;

        int sum = 0;
        sum += lcc - less;
        sum += gre - gcc;
        // if(sum < ans){
        //     cout << kk << " " << sum << endl;
        // }
        ans = min(ans, sum);
        kk = kk + k;
    }

    cout << ans << endl;

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
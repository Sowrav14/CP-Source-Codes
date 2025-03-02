#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int oc[N];
int where[N];

void solve(){

    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        oc[i] = 1;
        where[i] = i;
    }
    int ans = 0;
    while(q--){
        int t; cin >> t;
        if(t == 2){
            cout << ans << endl;
        } else {
            int a, b; cin >> a >> b;
            int x = where[a];
            int y = b;

            if(oc[x] > 1) ans--;
            oc[x]--;
            if(oc[x] > 1) ans++;
            if(oc[y] > 1) ans--;
            oc[y]++;
            if(oc[y] > 1) ans++;
            where[a] = y;
        }     
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
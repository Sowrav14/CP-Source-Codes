#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int spf[N];
void sieve() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}


void solve(){

    sieve();
    int n; cin >> n;

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(x == 1){
            cout << 1 << endl;
            continue;
        }
        map<int,int> m;
        while(x!=1){
            m[spf[x]]++;
            x /= spf[x];
        }

        int ans =  1;
        for(auto i : m){
            ans *= (i.second + 1);
        }
        cout << ans << endl;
    }

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
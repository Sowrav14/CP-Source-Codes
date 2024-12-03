#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int P1 = 1e9 + 7, P2 = 127657753;
const int inf = 1e12;
const int M1 = 1e9 + 9, M2 = 987654319;



// Big Mod
int A_pow_B(int a,int b, int mod){
    int ret = 1;
    while(b){
        if(b&1) {
            ret = (1ll * ret%mod * a%mod) % mod;
        }
        a = (1ll * a%mod * a%mod) % mod;
        b >>= 1;
    }
    return ret;
}

int n;
int a[N], b[N];
int ha[N], hb[N];
int haa[N], hbb[N];

void setHash(){
    map<int,int>ma, mb;
    for(int i=1;i<=n;i++){
        ha[i] = ha[i-1]; haa[i] = haa[i-1];
        hb[i] = hb[i-1]; hbb[i] = hbb[i-1];
        if(!ma[a[i]]){
            ha[i] = (ha[i]%M1 + A_pow_B(a[i] + P1, P1, M1)%M1)%M1;
            haa[i] = (haa[i]%M2 + A_pow_B(a[i] + P2, P2, M2)%M2)%M2;
        }
        if(!mb[b[i]]){
            hb[i] = (hb[i]%M1 + A_pow_B(b[i] + P1, P1, M1)%M1)%M1;
            hbb[i] = (hbb[i]%M2 + A_pow_B(b[i] + P2, P2, M2)%M2)%M2;
        }
        ma[a[i]]++;
        mb[b[i]]++;
    }
}

void solve(){

    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    setHash();

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(ha[x] == hb[y] and haa[x] == hbb[y]){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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
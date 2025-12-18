#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
f[i] = expected spins from i
represent f[i] = k[i]*f[0] + b[i]

base:
i >= n -> f[i]=0 => k=0,b=0
i in trap -> f[i]=f[0] => k=1,b=0

transition:
f[i] = 1 + (1/m)*sum_{j=i+1..i+m} f[j]
k[i] = (1/m)*sum k[j]
b[i] = 1 + (1/m)*sum b[j]

finally:
f[0] = k[0]*f[0] + b[0]
if k[0] >= 1 -> impossible
else f[0] = b[0]/(1-k[0])
*/

void solve(){
    int n,m,k; 
    cin >> n >> m >> k;
    vector<int> trap(n+1,0);
    for(int i=0;i<k;i++){
        int x; cin >> x;
        trap[x]=1;
    }

    vector<long double> kk(n+m+5,0.0L), bb(n+m+5,0.0L);
    vector<long double> sk(n+m+5,0.0L), sb(n+m+5,0.0L);

    for(int i=n-1;i>=0;i--){
        if(trap[i]){
            kk[i]=1.0L;
            bb[i]=0.0L;
        }else{
            long double sumk = sk[i+1] - sk[i+m+1];
            long double sumb = sb[i+1] - sb[i+m+1];
            kk[i] = sumk / (long double)m;
            bb[i] = 1.0L + sumb / (long double)m;
        }
        sk[i] = sk[i+1] + kk[i];
        sb[i] = sb[i+1] + bb[i];
    }

    if(kk[0] >= 1.0L - 1e-12){
        cout << -1 << endl;
        return;
    }

    long double ans = bb[0] / (1.0L - kk[0]);
    cout << fixed << setprecision(10) << ans << endl;
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

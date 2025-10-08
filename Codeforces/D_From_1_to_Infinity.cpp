#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int digit_sum(int k) {
    if (k <= 0) return 0;
    
    string s = to_string(k);
    int n = s.size();
    int ans = 0;
    
    for (int i=0;i<n;i++) {
        int p = 1;
        for (int j=0;j<i;j++) p *= 10;
        int pre = k / (p * 10);
        int dig = s[n - 1 - i] - '0';
        int suf = k % p;
        ans += pre * p * 45;
        for (int d=0;d<dig;d++) {
            ans += d * p;
        }
        ans += dig * (suf + 1);
    }
    
    return ans;
}


void solve(){

    int k; cin >> k;
    int x, rem = 0;
    int t = 9, d = 1, st = 1;
    while(1){
        if(k == 0) break;
        if(k >= t*d){
            k -= t*d;
            x = st * 10 - 1;
            rem = 0;
        } else {
            // cout << k << " " << d << " " << t << endl;
            int temp = k / d;
            rem = k % d;
            x = st + temp - 1;
            break;
        }
        t *= 10;
        d++;
        st *= 10;
    }

    // cout << x << " " << rem << endl;
    int ans = digit_sum(x);

    string res = to_string(x+1);
    for(int i=0;i<rem;i++) ans += (int)(res[i] - '0');
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
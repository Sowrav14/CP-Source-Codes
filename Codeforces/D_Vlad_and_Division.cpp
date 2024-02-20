#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int flippingBits(unsigned long N)
{
 
    unsigned long K = 32;
    // Stores (2 ^ K) - 1
    unsigned long X = (1 << (K - 1)) - 1;
 
    // Update N
    N = X - N;
 
    // Print the answer
    return N;
}

void solve(){

    int n; cin >> n;
    map<int,int>m;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        m[x]++;
    }
    int ans = 0;
    for(auto i : m){
        int x = i.first;
        if(i.second == 0) continue;
        int flipped = flippingBits(x);
        if(m[flipped]){
            int xx = min(i.second, m[flipped]);
            ans += xx;
            ans += i.second - xx;
            ans += m[flipped] - xx;
            m[flipped] = 0;
            m[x] = 0;
        } else{
            ans += i.second;
            m[x] = 0;
        }

        // cout << i.first << " " << flipped << " " << ans << endl;
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
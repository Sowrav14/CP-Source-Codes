#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nein cout << "NO" << endl;
#define ja cout << "YES" << endl;
#define danke cout << " ----- " << endl;

void solve(){

    int n,k; cin >> n >> k;
    if(k == 1){
        ja;
        cout << n << endl;
        return;
    }
    int tot = k * (k + 1);
    tot /= 2;
    int rem = (n - tot);

    if(rem < 0){
        nein;
        return;
    }

    int x = rem % k;
    x = k - x;

    vector<int> ans(k+1, 0);
    for(int i=1;i<=x;i++){
        ans[i] = i;
        ans[i] += (rem / k);
    }
    for(int i=x+1;i<=k;i++){
        ans[i] = i;
        ans[i] += ceil(rem / (k * 1.0));
    }

    if(rem == k-1){
        if(k < 4){
            nein;
            return;
        } else{
            ans[2] -= 1;
            ans[k] += 1;
        }
    }

    ja;
    for(int i=1;i<=k;i++) cout << ans[i] << " "; cout << endl;


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
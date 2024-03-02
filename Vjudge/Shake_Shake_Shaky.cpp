#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

vector<int>a;
int n,p;

bool check(int m){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += a[i] / m;
    }
    return cnt >= p;
}


void solve(){

    a.clear();
    cin >> n >> p;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    // sort(a.begin(), a.end());

    int l = 1, r = 1e12;
    int ans = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
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
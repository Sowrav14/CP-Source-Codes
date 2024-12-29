#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int>v;
int n, k;

int check(int m){
    int ret = 0;
    for(auto i : v){
        ret += abs(i - m * k);
    }
    return ret;
}


void solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int l = 0, r = 1000000;
    while(r - l > 2){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        int x = check(m1);
        int y = check(m2);

        if(x < y){
            r = m2;

        } else {
            l = m1;
        }
    }
    int ans = inf;
    for(int i=l;i<=r;i++){
        ans = min(ans, check(i));
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
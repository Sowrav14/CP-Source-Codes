#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct XXX{
    int x, y, d;
};

int a[N], b[N], p[N], q[N];
int prep[N], preq[N];
vector<XXX>v;


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        b[i] += b[i-1];
    }

    for(int i=1;i<=n;i++){
        XXX t;
        t.x = p[i];
        t.y = q[i];
        t.d = p[i] - q[i];
        v.push_back(t);
    }
    // cout << v.size() << endl;
    sort(v.begin(), v.end(), [](XXX x1, XXX x2){
        if(x1.d != x2.d) return x1.d < x2.d;
        else return x1.x < x2.x;
    });

    // for(auto i : v){
    //     cout << i.d << endl;
    // }
    for(int i=1;i<=n;i++){
        prep[i] += prep[i-1] + v[i-1].x;
    }
    for(int i=n;i>=1;i--){
        preq[i] = preq[i+1] + v[i-1].y;
        // cout << preq[i] << " ";
    } 
    // cout << "HERE" << endl;

    int ans  = preq[1] + b[n];
    for(int i=0;i<=n;i++){
        int j = n - i;
        int x = prep[i] + a[i];
        int y = preq[i+1] + b[j];
        // cout << x << " " << y << endl;
        ans = min(ans, x + y);
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
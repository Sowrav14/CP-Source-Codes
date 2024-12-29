#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int gg(int a, int b, int c, int k){
    int extra = ceil(a/(k*1.0)) - 1;
    int extrb = ceil(b/(k*1.0)) - 1;
    int extrc = ceil(c/(k*1.0)) - 1;
    
    int ans = a + b + c;
    if(extra > b + c){
        int x = extra - b - c;
        ans += (x%2 ? x + 1 : x);
    }
    if(extrb > a + c){
        int x = extrb - a - c;
        ans += (x%2 ? x + 1 : x);
    }
    if(extrc > a + b){
        int x = extrc - a - b;
        ans += (x%2 ? x + 1 : x);
    }
    return ans;
}


void solve(){

    int a, b, c; cin >> a >> b >> c;
    int x, y, z; cin >> x >> y >> z;
    int k; cin >> k;

    int xx = abs(a-x);
    int yy = abs(b-y);
    int zz = abs(c-z);

    cout << gg(xx, yy, zz, k) << endl;

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
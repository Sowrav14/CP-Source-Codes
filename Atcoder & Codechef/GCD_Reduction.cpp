#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int check(vector<int> a) {
    while (a.size() > 2) {
        int g1 = gcd(a[0], a[2]);
        int g2 = gcd(a[1], a[2]);
        if (g1 <= g2) a.erase(a.begin());
        else a.erase(a.begin() + 1);
    }
    return a[0];
}


void solve(){

    int n, x, y; cin >> n >> x >> y;

    vector<int> ans;
    for(int i=1;i<=n;i++) {
        if(i != x and i != y) ans.push_back(i);
    }
    
    sort(ans.begin(), ans.end(), [&](int a, int b) {
        return gcd(a, y) < gcd(b, y);
    });
    ans.push_back(y), ans.push_back(x);
    
    // for(auto i : ans) cout << i << " --- "; cout << endl;
    if(check(ans) == y){
        reverse(ans.begin(), ans.begin() + n - 2);
        if(check(ans) == y){
            cout << -1 << endl;
            return;
        }
    }
    
    for(auto i : ans) cout << i << " "; cout << endl;

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
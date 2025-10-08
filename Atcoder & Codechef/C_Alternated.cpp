#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    string s; cin >> s;
    string a, b;
    int f = 0;
    for(int i=0;i<2*n;i++){
        a += (char)('A' + f);
        b += (char)('A' + 1 - f);
        f = 1 - f;
    }
    // cout << a << " " << b << endl;

    vector<int> bs, ba, bb;
    for(int i=0;i<2*n;i++){
        if(s[i] == 'B') bs.push_back(i);
        if(a[i] == 'B') ba.push_back(i);
        if(b[i] == 'B') bb.push_back(i);
    }

    int ans = 0, res = 0;
    for(int i=0;i<n;i++){
        ans += abs(bs[i] - ba[i]);
        res += abs(bs[i] - bb[i]);
    }

    cout << min(ans, res) << endl;

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
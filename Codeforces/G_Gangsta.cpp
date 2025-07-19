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
    vector<int> pref{0};
    for(int i=0;i<n;i++){
        int x = pref.back();
        if(s[i] == '0') x--;
        else x++;
        pref.push_back(x);
    }

    sort(pref.begin(), pref.end());

    int ans = 0;
    for(int i=0;i<=n;i++){
        ans += (pref[i] * i) - (pref[i] * (n - i));
        ans += i * (n - i + 1);
    }
    ans /= 2;
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
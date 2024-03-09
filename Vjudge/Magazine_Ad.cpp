#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,k;
string s;

bool check(int m){
    int last = 0;
    int x = 0;
    while(1){
        if(last >= n) break;
        int cur = min(last + m - 1, n);
        int flag = 0;
        while(cur >= last){
            if(s[cur] == '.' or s[cur] == '-' or cur == n-1){
                // for(int i=last;i<=cur;i++) cout << s[i]; cout << endl;
                last = cur + 1;
                x++;
                flag = 1;
                break;
            } else{
                cur--;
            }
        }
        if(flag == 0) return false;
    }
    return x <= k;
}


void solve(){

    cin >> k;
    // cin >> s;
    cin.ignore();
    getline(cin, s, '\n');
    n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == ' ') s[i] = '.';
    }
    s += '.';
    // cout << n << endl;
    // cout << s << endl;
    // cout << check(10) << endl;


    int l = 1, r = n;
    int ans;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << ans << endl;

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
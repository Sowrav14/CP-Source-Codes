#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n;
string a, b;
int x, cnt;
int tot = 0, success = 0;

void recur(int i, int y){
    if(i == 0){
        tot++;
        if(x == y) success++;
        return;
    }

    recur(i - 1, y + 1);
    recur(i - 1, y - 1);
    return;
}


void solve(){

    cin >> a >> b;
    n = a.size();
    x = 0;
    for(int i=0;i<n;i++){
        a[i] == '+' ? x++ : x--;
    }
    int y = 0;
    cnt = 0;
    for(int i=0;i<n;i++){
        if(b[i] == '?') cnt++;
        else if(b[i] == '+') y++;
        else y--;
    }
    // cout << x << " " << y << endl;
    double ans = 0;
    if(cnt != 0){
        recur(cnt, y);
        if(tot != 0) ans = (success / (tot * 1.0));
        else ans = 0;
        // cout << tot << " " << success << endl;
    } else if(x == y){
        ans = 1;
    }

    cout << fixed << setprecision(12) << ans << endl;
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
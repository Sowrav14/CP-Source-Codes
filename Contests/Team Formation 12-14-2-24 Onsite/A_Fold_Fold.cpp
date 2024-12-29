#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int l, w, a;

bool recur(float x, float y){
    if(x * y == a) return true;
    if(x * y < a) return false;

    bool ans = recur(x/2.0, y);
    ans  |= recur(x, y/2.0);

    return ans;
}

void solve(){

    cin >> l >> w >> a;
    // cout << recur(l, w) << endl;
    int ans = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int x = (1 << i);
            int y = (1 << j);

            if((l * w) == (x * y * a)) ans = 1;
        }
    }
    cout << (ans ? "YA" : "TIDAK") << endl;

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
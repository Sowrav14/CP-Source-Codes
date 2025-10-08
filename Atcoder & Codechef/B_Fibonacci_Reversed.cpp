#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int get(int x, int y){
    int z = x + y;
    string s = to_string(z);
    reverse(s.begin(), s.end());
    int zz = stoll(s);
    return zz;
}

void solve(){

    int x, y; cin >> x >> y;
    
    for(int i=3;i<=10;i++){
        int z = get(x, y);
        x = y;
        y = z;
    }

    cout << y << endl;

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
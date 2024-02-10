#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


set<pair<int,int>>ans;

void write(int x, int y){
    if(x > y) swap(x, y);
    if((x+y)%2 == 0) return;
    int sum = x + y;
    int twom = sum - 1;
    int m = twom / 2;

    int n = m - x;
    if(n < 1 or m < 1) return;
    ans.insert({n, m});
}


void solve(){

    int d; cin >> d;
    d *= 2;
    for(int i=1;i*i<=d;i++){
        if(d%i == 0){
            int x = i;
            int y = d / i;
            // cout << x << " " << y << endl;
            write(x, y);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
    }

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

set<int>a[N];

void solve(){

    int n, x, y; cin >> n >> x >> y;
    for(int i=1;i<=n;i++){
        a[i].clear();
        if(i==1){
            a[i].insert(n);
            a[i].insert(2);
        } else if(i == n){
            a[i].insert(n-1);
            a[i].insert(1);
        } else {
            a[i].insert(i+1);
            a[i].insert(i-1);
        }
    }

    a[x].insert(y);
    a[y].insert(x);

    for(int i=1;i<=n;i++){
        int mex = 0;
        for(auto j : a[i]) cout << j << " "; cout << endl;
        while(!a[i].empty()){
            if(a[i].find(mex) != a[i].end()){
                a[i].erase(mex);
                mex++;
            } else {
                break;
            }
        }
        cout << mex << " ";
    }
    cout << endl;

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
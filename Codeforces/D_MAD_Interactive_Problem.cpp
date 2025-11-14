#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;
    int m = 2 * n;
    multiset<int> ms;
    vector<int> ans(m+1, 0);

    function<int()> query = [&]() -> int {
        cout << "? " << ms.size() << " ";
        for(auto &x : ms) cout << x << " ";
        cout << endl;

        int ret; cin >> ret;
        return ret;
    };

    for(int i=1;i<=m;i++){
        ms.insert(i);
        int x = query();
        if(x > 0) {
            ans[i] = x;
            ms.erase(i);
        }
    }

    ms.clear();
    for(int i=1;i<=m;i++){
        if(ans[i] != 0) ms.insert(i);
    }

    for(int i=1;i<=m;i++){
        if(ans[i] == 0){
            ms.insert(i);
            int x = query();
            ans[i] = x;
            ms.erase(i);
        }
    }

    cout << "! ";
    for(int i=1;i<=m;i++) cout << ans[i] << " "; 
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
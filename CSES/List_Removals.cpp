#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
const int N = 200010;
int bit[N], a[N];
int n;
 
// updating a single value in bit
void update(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += (idx) & (-idx);  // lsb will be added.
    }
}
 
// return sum of (1 - idx)
int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);  // lsb will be substracted.
    }
    return ret;
}
 
 
void solve(){
 
    cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        a[i] = x;
        update(i, 1);
    }
 
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        int id = -1;
        int l = x, r = n;
        while(l <= r){
            int m = (l + r) / 2;
            int p = query(m);
            if(p >= x){
                id = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        update(id, -1);
        cout << a[id] << " ";
 
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

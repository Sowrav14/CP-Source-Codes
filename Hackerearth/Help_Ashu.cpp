#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;

int n;
vector<int> a(N); 
vector<int> odd(N), even(N);

void update(int idx, int val, vector<int> &bit){
    while(idx <= n){
        bit[idx] += val;
        idx += (idx) & (-idx);
    }
}

int query(int idx, vector<int> &bit){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);
    }
    return ret;
}


void solve(){

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]%2) {
            update(i, 1, odd);
        } else {
            update(i, 1, even);
        }
    }

    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int t,x,y; cin >> t >> x >> y;
        if(t == 0){
            int temp = query(x, even) - query(x-1, even);
            if(temp == 1){
                if(y%2){
                    update(x, -1, even);
                    update(x, 1, odd);
                }
            } else{
                if(y%2 == 0){
                    update(x, -1, odd);
                    update(x, 1, even);
                }
            }
        } else if(t == 1){
            cout << query(y, even) - query(x-1, even) << endl;
        } else {
            cout << query(y, odd) - query(x-1, odd) << endl;
        }
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
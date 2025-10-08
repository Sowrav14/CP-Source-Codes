#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e7 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

bool is_prime[N];
void sieve() {
    for (int i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void solve(){

    int n, q; cin >> n >> q;
    set<int> pr{0, n+1};
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        if(is_prime[x]) pr.insert(i+1);
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            auto lt = pr.lower_bound(x);
            auto rt = pr.upper_bound(x);

            int l = *(--lt), r = *rt;
            cout << r - l - 2 << endl;
        } else {
            int id, y; cin >> id >> y;
            if(is_prime[y]){
                pr.insert(id);
            } else {
                pr.erase(id);
            }
        }
    }

}


signed main(){
    Fast_IO()
    sieve();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
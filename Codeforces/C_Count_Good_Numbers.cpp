#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> primes = {2, 3, 5, 7};
vector<int> guns(16);
int n = 4;

void generate(){
    guns[0] = 1;
    for(int i=1;i<(1<<n);i++){
        int gun = 1;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                gun *= primes[j];
            }
        }
        guns[i] = gun;
    }
}

void solve(){

    int l, r; cin >> l >> r;
    
    int total = r - l + 1;
    
    int red = 0;
    for(int i=1;i<(1<<n);i++){
        int sg = (__builtin_popcount(i) % 2 == 1) ? 1 : -1;
        int cnt = (r / guns[i]) - ((l-1) / guns[i]);
        red += sg * cnt;
    }
    total -= red;
    cout << total << '\n';

}


signed main(){
    Fast_IO()
    generate();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
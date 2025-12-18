#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

int32_t main(){
    Fast_IO()
    int T;
    cin >> T;
    while(T--){
        unsigned long long n_in, k_in;
        cin >> n_in >> k_in;
        long long n = (long long)n_in;
        long long k = (long long)k_in;
        if(k == 0) {
            cout << (n == 0 ? 1 : 0) << endl;
            continue;
        }
        if(k > n){
            cout << 0 << endl;
            continue;
        }
        // Apply the Sierpiński / bitwise formula
        int ans = (((n - k) & ((k - 1) / 2)) == 0) ? 1 : 0;
        cout << ans << endl;
    }
    return 0;
}

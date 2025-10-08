#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


void solve(){

    int n, q; cin >> n >> q;
    vector<int> ms(q);
    for(int i=0;i<q;i++) cin >> ms[i];
    vector<int> divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(i != n/i){
                divisors.push_back(n/i);
            }
        }
    }

    map<int,int> phis;
    for(int d : divisors){
        phis[d] = phi(n/d);
    }

    for(int i=0;i<q;i++)
        cout << (n % ms[i] ? 0 : phis[ms[i]]) << " \n"[i == q-1];

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case " << i << ": ";
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int digitsum(int n){
    int sum = 0;
    while(n > 0){
        int x = n % 10;
        n /= 10;
        sum += x;
    }
    return sum;
}

int a[200010];

void digit(){
    for(int i=1;i<=200005;i++){
        a[i] = digitsum(i);
    }

    for(int i=2;i<200005;i++){
        a[i] += a[i-1];
    }
}

void solve(){

    int n; cin >> n;
    // cout << digitsum(12) << endl;
    cout << a[n] << endl;
    // cout << ans << endl;

}


signed main(){
    Fast_IO()
    digit();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
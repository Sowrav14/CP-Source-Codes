#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 110;
int n;
int a[N];

/*
 *  subset of {1, 2, 3, 4}
 *            {1}, {2}, {3}, {4}
 *            {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}
 *            {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}
 *            {1, 2, 3, 4}
 * 
 *            every one occured 8(pow(2, 4-1)) times.
*/



int subsetsum(){
    int ret = 0;
    int cnt = pow(2, n-1);
    for(int i=1;i<=n;i++){
        ret += a[i] * cnt;
    }
    return ret;
}

void solve(){

    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }

    cout << subsetsum() - sum << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
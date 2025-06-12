#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 998244353;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> dp1(k+1, 0); // number of ways where last element is i
    vector<int> dp2(k+1, 0); // number of ways where last element is less or equal to i

    int p = 1;
    for(int i=0;i<n;i++){
        vector<int> tdp1(k+1, 0); // temporary dp1 to store the current state
        vector<int> tdp2 = dp2; // temporary dp2 to store the current state
        int cur = a[i];
        if(cur != -1){
            int prev = dp2[cur-1];
            tdp1[cur] += prev;
            tdp1[cur] %= M;

            tdp1[cur] += p;
            tdp1[cur] %= M;

            for(int j=cur;j<=k;j++){
                tdp2[j] += tdp1[cur];
                tdp2[j] %= M;
            }
        } else {
            int sum = 0;
            for(int j=1;j<=k;j++){
                int prev = dp2[j-1];
                tdp1[j] = prev;
                tdp1[j] %= M;

                tdp1[j] += p;
                tdp1[j] %= M;

                sum += tdp1[j];
                sum %= M;
                
                tdp2[j] = ((dp2[j]%M * k%M)%M + sum%M)%M;
            }
            p = (p%M * k%M)%M;
        }
        swap(dp1, tdp1); // update dp1 with the temporary dp1
        swap(dp2, tdp2); // update dp2 with the temporary dp2
    }
    cout << dp2[k] << endl;

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
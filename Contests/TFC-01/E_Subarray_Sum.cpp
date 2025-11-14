#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e15;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = -inf;
    for(int l=0;l<n;l++){
        priority_queue<int> neg;
        int sum = 0;
        for(int r=l;r<n;r++){
            if(v[r] > 0) {
                sum += v[r];
            } else {
                neg.push(v[r]);
            }

            while(neg.size() > k){
                sum += neg.top();
                neg.pop();
            }
            // if(sum > ans){
            //     cout << l << " " << r << " " << sum << " " << neg.size() << endl;
            // }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

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
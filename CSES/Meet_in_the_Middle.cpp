#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n, k; cin >> n >> k;
    vector<int> left, right;
    for(int i=0;i<n/2;i++){
        int x; cin >> x;
        left.push_back(x);
    }
    for(int i=n/2;i<n;i++){
        int x; cin >> x;
        right.push_back(x);
    }
    
    auto subsets = [&](vector<int>&v) -> vector<int> {
        vector<int> ans;
        int n = v.size();
        for(int i=0;i<(1<<n);i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    sum += v[j];
                }
            }
            ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        return ans;
    };

    vector<int> left_subsets = subsets(left);
    vector<int> right_subsets = subsets(right);

    int ans = 0;
    for(auto &x : left_subsets){
        int y = k - x;
        auto it = lower_bound(right_subsets.begin(), right_subsets.end(), y);
        auto it2 = upper_bound(right_subsets.begin(), right_subsets.end(), y);
        ans += (it2 - it);
    }
    cout << ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
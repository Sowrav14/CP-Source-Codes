#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int n, m;
int x;
vector<vector<int>>ans;
void recur(vector<int>&nums){
    int i = nums.size();
    if(i == n){
        ans.push_back(nums);
    }
    int s = (i == 0 ? 1 : nums.back() + 10);
    int f = m - ((n - i - 1) * 10);
    // cout << s << " " << f << endl;
    for(int it=s;it<=min(f, m);it++){
        nums.push_back(it);
        recur(nums);
        nums.pop_back();
    }
}

void solve(){

    cin >> n >> m;
    vector<int>nums;
    recur(nums);

    cout << ans.size() << endl;
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        } cout << endl;
    }

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
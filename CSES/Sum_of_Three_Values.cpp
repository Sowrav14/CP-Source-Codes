#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n,sum; cin >> n >> sum;
    vector<pair<int,int>>arr;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        arr.push_back({x, i});
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++){
        int l = 0, r = n - 1;
        int x = sum - arr.at(i).first;
        while(l != r){
            if(l != i and r != i and arr.at(l).first + arr.at(r).first == x){
                cout << arr.at(i).second << " " << arr.at(l).second << " " << arr.at(r).second << endl;
                return;
            }
            if(arr.at(l).first + arr.at(r).first < x){
                l++;
            } else{
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

}

signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
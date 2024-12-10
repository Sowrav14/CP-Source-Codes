#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int recur(vector<int>a){
    if(a.size() == 0) return 0;
    // if(a.size() == 1) return a.back();
    int mn = *min_element(a.begin(), a.end());
    int ans = mn;
    vector<int>temp;
    for(int i=0;i<a.size();i++){
        // cout << i << " " << a[i] <<  endl;
        int x = a[i] - mn;
        if(x == 0){
            ans += recur(temp);
            temp.clear();
        } else {
            temp.push_back(x);
        }
    }
    ans += recur(temp);
    return ans;
}


void solve(){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    cout << recur(v) << endl;

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
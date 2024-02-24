#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n, k; cin >> n >> k;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++) cin >> a[i].second;
    for(int i=0;i<n;i++) cin >> a[i].first, a[i].first = abs(a[i].first);

    sort(a.begin(), a.end());

    // for(auto i : a) cout << i.first << " " << i.second << endl;

    int str = 0;
    int left = 0;
    for(int i=0;i<n;i++){
        int x = a[i].first;
        int h = a[i].second;
        if(h < left){
            left -= h;
            continue;
        } else{
            h -= left;
            left = 0;
        }
        int need = ceil(h / (k*1.0));
        left = need * k - h;
        str += need;
        // cout << str << " " << need << " " << left << endl;
        if(str > x){
            cout << "NO" << endl;
            return;
        }

    }
    cout << "YES" << endl;

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
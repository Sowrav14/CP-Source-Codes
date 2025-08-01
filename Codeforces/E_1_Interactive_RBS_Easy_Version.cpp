#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int n; cin >> n;

    cout << "? " << n << " ";
    for(int i=1;i<=n;i++) cout << i << " "; cout << endl;
    int x; cin >> x;
    if(x == 0){
        int l = 2, r = n;
        int id = 2;
        while(l <= r){
            int m = (l + r) / 2;
            cout << "? " << 2 << " " << m << " " << 1 << endl;
            int x; cin >> x;
            if(x == 0){
                l = m + 1;
            } else {
                id = m;
                r = m - 1;
            }
        }
        //cout << l << " " << r << endl;

        cout << "! ";
        for(int i=1;i<id;i++){
            cout << ")";
        }
        for(int i=id;i<=n;i++){
            cout << "(";
        }
        cout << endl;
        return;
    }
    int l = 1, r = n;
    while(l < r){
        if(l + 1 == r){
            break;
        }
        int m = (l + r) / 2;
        cout << "? " << m - l + 1 << " ";
        for(int i=l;i<=m;i++) cout << i << " "; cout << endl;
        int x; cin >> x;
        if(x == 0){
            l = m;
        } else {
            r = m;
        }
    }

    // cout << l << " " << r << endl;

    vector<int> ans(n+1);
    ans[l] = 0;
    ans[r] = 1;
    int i = 1;
    while(i < l){
        if(i + 1 < l){
            cout << "? " << 6 << " " << i << " " << r << " " << i << " " << r << " " << l << " " << i + 1 << endl;
            int x; cin >> x;
            if(x == 0){
                ans[i] = 1;
                ans[i+1] = 0;
            } else if(x == 3){
                ans[i] = 0;
                ans[i+1] = 0;
            } else if(x == 1){
                ans[i] = 1;
                ans[i+1] = 1;
            } else {
                ans[i] = 0;
                ans[i+1] = 1;
            }
            i += 2;
        } else {
            cout << "? " << 2 << " " << i << " " << r << endl;
            int x; cin >> x;
            if(x == 0){
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
            i++;
        }
    }

    i = r + 1;
    while(i <= n){
        if(i + 1 <= n){
            cout << "? " << 6 << " " << i << " " << r << " " << i << " " << r << " " << l << " " << i + 1 << endl;
            int x; cin >> x;
            if(x == 0){
                ans[i] = 1;
                ans[i+1] = 0;
            } else if(x == 3){
                ans[i] = 0;
                ans[i+1] = 0;
            } else if(x == 1){
                ans[i] = 1;
                ans[i+1] = 1;
            } else {
                ans[i] = 0;
                ans[i+1] = 1;
            }
            i += 2;
        } else {
            cout << "? " << 2 << " " << i << " " << r << endl;
            int x; cin >> x;
            if(x == 1){
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
            i++;
        }
    }
    // for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;
    cout << "! ";
    for(int i=1;i<=n;i++){
        cout << (ans[i] == 0 ? '(' : ')');
    }
    cout << endl;

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

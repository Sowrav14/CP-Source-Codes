#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

vector<int> a, b;
int cnt[N];


bool check(int x){
    for(int i=0;i<a.size();i++){
        cnt[a[i] % x] = 0;
        cnt[b[i]] = 0;
    }
    for(int i=0;i<a.size();i++){
        cnt[a[i] % x]++;
    }
    for(int i=0;i<b.size();i++){
        if(b[i] >= x) return 0;
        if(cnt[b[i]] == 0) return 0;
        cnt[b[i]]--;
    }
    return 1;
}


void solve(){

    int n; cin >> n;
    a.clear(); b.clear();
    a.resize(n), b.resize(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        sum -= b[i];
    }
    if(sum == 0){
        if(check(1e6+10)){
            cout << (int)1e6+10 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    for(int i=1;i*i<=sum;i++){
        if(sum % i == 0){
            if(check(i)){
                cout << i << endl;
                return;
            }

            if(i != sum/i){
                if(check(sum/i)){
                    cout << (int)(sum/i) << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;

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
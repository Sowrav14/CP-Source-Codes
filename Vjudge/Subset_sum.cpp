#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 110;
int n;
int a[N];
set<int>s;


void subsetsum(int i, int sum){
    if(i > n){
        s.insert(sum);
        return;
    }

    subsetsum(i+1, sum);
    subsetsum(i+1, sum + a[i]);
}

void solve(){

    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    s.clear();
    subsetsum(1, 0);
    int ans = 0;
    for(auto i : s){
        ans += i;
    }
    cout << ans << endl;

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    multiset<int> ms;
    int a,b,c; cin >> a >> b >> c;
    ms.insert(a); ms.insert(b), ms.insert(c);

    for(int i=1;i<=5;i++){
        int x = *ms.begin(); x++;
        ms.erase(ms.begin());
        ms.insert(x);
    }

    int ans = 1;
    for(auto i : ms){
        ans *= i;
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
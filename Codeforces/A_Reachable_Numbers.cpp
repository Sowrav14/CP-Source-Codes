#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    
    set<int>s;
    s.insert(n);
    int flag = 0;
    while(1){
        n += 1;
        if(s.find(n) != s.end()) flag++;
        if(flag >= 2) break;
        while(n%10 == 0){
            n /= 10;
        }
        // cout << n << " ";
        s.insert(n);
    }
    cout << s.size() << endl;

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
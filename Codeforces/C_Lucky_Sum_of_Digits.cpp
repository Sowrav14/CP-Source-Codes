#include<bits/stdc++.h>
using namespace std;





void solve(){

    int n; cin >> n;
    int s,f;
    bool flag = false;
    for(int i=n/7;i>=0;i--){
        s = i;
        f = (n - (7 * s)) / 4;
        // cout << ss << " " << ff << endl;
        if(n == s * 7 + f * 4){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i=0;i<f;i++) cout << 4;
        for(int i=0;i<s;i++) cout << 7;
    } else{
        cout << -1 << endl;
    }

}


int main(){
    int t; 
    t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
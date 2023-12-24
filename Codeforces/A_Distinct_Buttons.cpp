#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n; cin >> n;
    int cnt[4] = {0};
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        if(x > 0) cnt[0] =  1;
        if(x < 0) cnt[1] = 1;
        if(y > 0) cnt[2] = 1;
        if(y < 0) cnt[3] = 1;
    }
    int x = cnt[1] + cnt[2] + cnt[3] + cnt[0];
    if(x == 4){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }

}


int main(){
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
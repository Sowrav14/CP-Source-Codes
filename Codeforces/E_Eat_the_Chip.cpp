#include<bits/stdc++.h>
using namespace std;
#define int long long int


void solve(){

    int h,w,a1,a2,b1,b2; cin >> h >> w >> a1 >> a2 >> b1 >> b2;
    if(a1 >= b1){
        cout << "Draw" << endl;
        return;
    }

    int diff = b1 - a1 - 1;
    int move = diff / 2;
    int alicel = max(1ll, a2-move);
    int alicer = min(w, a2+move);
    int bobl = max(1ll, b2-move);
    int bobr = min(w, b2+move);
    if(diff % 2 == 0){
        alicel = max(1ll, alicel-1);
        alicer = min(w, alicer+1);
        // cout << move << " " << alicel << " " << alicer << " " << bobl << " " << bobr << endl;
        if(bobl >= alicel and bobr <= alicer){
            cout << "Alice" << endl;
        } else {
            cout << "Draw" << endl;
        }
    } else {
        alicel = max(1ll, alicel-1);
        alicer = min(w, alicer+1);
        bobl = max(1ll, bobl-1);
        bobr = min(w, bobr+1);
        if(alicel >= bobl and alicer <= bobr){
            cout << "Bob" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
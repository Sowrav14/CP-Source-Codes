#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    vector<int>cards(15, 0);
    int alice = 0, bob = 0;
    int n; cin >> n;
    int x, y; cin >> x >> y;
    cards[x]++;
    cards[y]++;
    x = x > 10 ? 10 : x;
    y = y > 10 ? 10 : y;
    bob += (x + y);

    cin >> x >> y;
    cards[x]++;
    cards[y]++;
    x = x > 10 ? 10 : x;
    y = y > 10 ? 10 : y;
    alice += (x + y);

    for(int i=0;i<n;i++) {
        int c; cin >> c;
        cards[c]++;
        c = c > 10 ? 10 : c;
        alice += c;
        bob += c;
    }

    for(int i=1;i<=13;i++){
        if(cards[i] == 4) continue;

        int point = ((i>=10) ? 10 : i);

        int now_alice = alice + point;
        int now_bob = bob + point;
        if(now_alice > 23){
            cout << -1 << endl;
            return;
        }
        if(now_alice == 23){
            cout << point << endl;
            return;
        }
        if(now_bob > 23){
            cout << point << endl;
            return;
        }
    }
    cout << -1 << endl;

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
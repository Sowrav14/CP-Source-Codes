#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

priority_queue<int, vector<int>, greater<int>>sq, nsq;

void is_square(int x){
    int t = sqrt(x);
    if(t*t == x){
        if(x == 0){
            sq.push(2);
        } else{
            sq.push(1);
        }
    } else{
        int a = t;
        int b = t + 1;

        a = (x - a * a);
        b = (b * b - x);
        nsq.push(min(a, b));
        // cout << min(a, b) << endl;
    }
}


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        is_square(x);
    }

    if(sq.size() == nsq.size()){
        cout << 0 << endl;
    } else if(sq.size() > nsq.size()){
        int ans = 0;
        while(sq.size() != nsq.size()){
            ans += sq.top();
            sq.pop();
            nsq.push(0);
        }
        cout << ans << endl;
    } else{
        int ans = 0;
        while(nsq.size() != sq.size()){
            ans += nsq.top();
            nsq.pop();
            sq.push(0);
        }
        cout << ans << endl;
    }

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    deque<int> dq;
    int n; cin >> n;
    int q; cin >> q;
    int x; cin >> x;
    dq.push_back(x);
    for(int i=1;i<n;i++){
        int el; cin >> el;
        // dq.push_back(el);
        int x = dq.front();
        int y = dq.back();
        if(i%2){
            if(x > y){
                dq.push_front(el);
            } else {
                dq.push_back(el);
            }
        } else {
            if(x > y){
                dq.push_back(el);
            } else {
                dq.push_front(el);
            }
        }
    }
    cout << min(dq.front(), dq.back()) << endl;

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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;

class domino{
    public:
        int id, x, h, d;
        domino(){}
        domino(int i, int xx, int hh){
            id = i;
            x = xx;
            h = hh;
            d = 1;
        }
        operator < (domino dom){
            return this->x > dom.x;
        }
}; domino dominos[N];


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x,h; cin >> x >> h;
        dominos[i] = domino(i, x, h);
    }
    sort(dominos+1, dominos+1+n);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j-=dominos[j].d){
            if(dominos[j].x > dominos[i].x+dominos[i].h-1) break;
            dominos[i].d += dominos[j].d;
        }
        ans[dominos[i].id] = dominos[i].d;
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " "; cout << endl;

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
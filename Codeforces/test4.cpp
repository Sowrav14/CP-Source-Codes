#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5+10;

class domino{
    public:
        int id, x, h;
        domino(){}
        domino(int i, int xx, int hh){
            id = i;
            x = xx;
            h = hh;
        }
        operator < (domino d){
            return this->x < d.x;
        }
}; domino dominos[N];


int st[4*N];
vector<int>xc,hc,ans;

void update(int node, int l, int r, int i, int val){
    if(i<l or i>r) return;
    if(l == r){
        st[node] = val;
        return;
    }

    int m = (l + r) / 2;
    update(2*node, l, m, i, val);
    update(2*node+1, m+1, r, i, val);
    st[node] = st[2*node] + st[2*node+1];
}

int getsum(int node, int l, int r, int i, int j){
    if(l>j or r<i) return 0;
    if(l>=i and r<=j) return st[node];

    int m = (l + r) / 2;
    int left = getsum(2*node, l, m, i, j);
    int right = getsum(2*node+1, m+1, r, i, j);
    return left+right;
}


void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x,h; cin >> x >> h;
        dominos[i] = {i, x, h};
    }
    sort(dominos+1, dominos+n+1);
    xc.resize(n+1, 0); hc.resize(n+1, 0); ans.resize(n+1, 0);
    for(int i=1;i<=n;i++){
        xc[i] = dominos[i].x;
        hc[i] = dominos[i].h;
        ans[i] = 1;
        // cout << xc[i] << " " << hc[i] << endl;
    }
    update(1, 1, n, n, 1);
    for(int i=n-1;i>=1;i--){
        int cur = xc[i];
        int range = xc[i] + hc[i] - 1;
        int it = upper_bound(xc.begin(), xc.end(), range) - xc.begin();
        it--;

        int add = getsum(1, 1, n, i+1, it);
        cout << i << " " << it << " " << add << endl;
        ans[i] = add + 1;
        update(1, 1, n, i, ans[i]);
    }

    for(int i=1;i<=n;i++) cout << ans[i] <<  " "; cout << endl;   

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
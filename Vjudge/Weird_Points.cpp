#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct BIT {
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 10) {}
    // update the value at idx by val.
	void update(int idx, int val){
        while(idx <= size){
            bit[idx] += val;
            idx += (idx) & (-idx);
        }
    }
    // sum from [1...idx]
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx) & (-idx);
        }
        return sum;
    }
    // update the value at [l...r] by val.
    void update(int l, int r, int val){
        update(l, val);
        update(r+1, -val);
    }
    // sum form [l...r]
    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

void solve(){

    int n,k; cin >> n >> k;
    vector<pair<int,int>>p(n+1);
    map<int,int>m;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        p[i] = {x, y};
        m[y] = 1;
    }
    int v = 1;
    for(auto &i : m){
        i.second = v;
        v++;
    }
    for(int i=1;i<=n;i++){
        p[i].second = m[p[i].second];
    }

    sort(p.begin()+1, p.end());
    BIT bit(n);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        int x = p[i].first;
        int y = p[i].second;

        int dom = bit.query(y);
        int non_dom = n - dom - 1;
        int weird = abs(dom - non_dom);
        if(weird >= k){
            ans++;
        }

        bit.update(y, 1);
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
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int blk;
struct offline{
    int l, r, id;
    bool operator < (offline x){
        if(l/blk == x.l/blk){
            return r < x.r;
        } else{
            return l/blk < x.l/blk;
        }
    }
};

int freq[1000010], counter[30010];
int ans[200010];



void solve(){

    int n; cin >> n;
    blk = sqrt(n)+1;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int q; cin >> q;
    vector<offline>query(q+1);
    query[0].l = 0, query[0].r = 0, query[0].id = 0;
    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        query[i].l = l;
        query[i].r = r;
        query[i].id = i;
    }
    sort(query.begin(), query.end());

    int prevl = 0, prevr = 0;
    for(int i=1;i<=q;i++){
        int curl = query[i].l;
        int curr = query[i].r;
        int idx = query[i].id;

        while(curl < prevl){
            prevl--;
            int x = a[prevl];
            freq[x]++;
            counter[freq[x]]++;
        }
        while(curr > prevr){
            prevr++;
            int x = a[prevr];
            freq[x]++;
            counter[freq[x]]++;
        }
        while(curl > prevl){
            int x = a[prevl];
            counter[freq[x]]--;
            freq[x]--;
            prevl++;
        }
        while(curr < prevr){
            int x = a[prevr];
            counter[freq[x]]--;
            freq[x]--;
            prevr--;
        }
        
        ans[idx] = counter[1];
    }

    for(int i=1;i<=q;i++) cout << ans[i] << endl;

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
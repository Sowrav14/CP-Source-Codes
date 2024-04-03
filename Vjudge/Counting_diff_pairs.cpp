#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e6+10;
int bit[N];

void update(int idx, int val){
    while(idx < N){
        bit[idx] += val;
        idx += (idx) & (-idx);  // lsb will be added.
    }
}

int get(int idx){
    int ret = 0;
    while(idx > 0){
        ret += bit[idx];
        idx -= (idx) & (-idx);
    }
    return ret;
}

const int blk = sqrt(N);
class query{

    public :
         int l,r,id,block;                // each query belongs to a block
         query() {}
         query(int l, int r, int id){
            this->l = l;
            this->r = r;
            this->id = id;
            this->block = l/blk;            // block number will be l/blk
         }

         bool operator < (query cq){        // sort according to block then r
            if(block != cq.block) return block < cq.block;
            else return r < cq.r;
         }

};

const int M = 5e4+10;
query qu[M];
int a[M];
int ans[M];

void solve(){

    int n,q,k; cin >> n >> q >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=q;i++){
        int l,r; cin >> l >> r;
        qu[i] = query(l, r, i);
    }

    sort(qu+1, qu+q+1);
    int prevl = 1, prevr = 0;
    int prev_ans = 0;

    for(int i=1;i<=q;i++){
        int curl = qu[i].l;
        int curr = qu[i].r;
        int idx = qu[i].id;

        while(curl < prevl){            // adding extra from left
            --prevl;
            int val = a[prevl];
            int up = val + k;
            int down = val - k;
            int x = get(up-1) - get(down);
            int y = get(N-5);
            prev_ans += (y - x);
            update(val, 1);

        }
        while(prevr < curr){            // adding extra from right.
            ++prevr;
            int val = a[prevr];
            int up = val + k;
            int down = val - k;
            int x = get(up-1) - get(down);
            int y = get(N-5);
            prev_ans += (y - x);
            update(val, 1);

        }
        while(prevl < curl){            // removing extra from left.
            int val = a[prevl];
            int up = val + k;
            int down = val - k;
            int x = get(up - 1) - get(down);
            int y = get(N-5);
            prev_ans -= (y - x);
            update(val, -1);
            prevl++;
        }
        while(prevr > curr){            // removing extra from right.
            int val = a[prevr];
            int up = val + k;
            int down = val - k;
            int x = get(up - 1) - get(down);
            int y = get(N-5);
            prev_ans -= (y - x);
            update(val, -1);
            prevr--;
        }

        ans[idx] = prev_ans;

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
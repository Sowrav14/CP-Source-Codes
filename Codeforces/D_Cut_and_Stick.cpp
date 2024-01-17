#include<bits/stdc++.h>
using namespace std;
const int N = 3*1e5+10;
const int blk = sqrt(N) + 10;

class query{
    public:
        int l,r,id,block;
        query(){}
        query(int left, int right, int idx){
            l = left;
            r = right;
            id = idx;
            block = l/blk;
        }

        bool operator < (query temp){
            if(this->block != temp.block){
                return this->block < temp.block;
            } else{
                return this->r > temp.r;
            }
        }

};


int a[N], freq[N], counter[N];
query qu[N];
int ans[N], range[N];


int main(){
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=q;i++){
        int l,r; cin >> l >> r;
        qu[i] = query(l, r, i);
        range[i] = r - l + 1;
    }

    sort(qu+1, qu+q+1);

    int pl = 0, pr = -1;
    int pm = 0;

    for(int i=1;i<=q;i++){
        int cl = qu[i].l;
        int cr = qu[i].r;
        int idx = qu[i].id;
        int rng = range[idx];

        while(cl < pl){
            pl--;
            int val = a[pl];
            int c = freq[val];
            counter[c]--;
            freq[val]++;
            counter[freq[val]]++;

            pm = max(pm, freq[val]);
        }
        while(cr > pr){
            pr++;
            int val = a[pr];
            int c = freq[val];
            counter[c]--;
            freq[val]++;
            counter[freq[val]]++;

            pm = max(pm, freq[val]);
        }
        while(cl > pl){
            int val = a[pl];
            int c = freq[val];
            counter[c]--;
            freq[val]--;
            counter[freq[val]]++;

            while(counter[pm] == 0) pm--;
            pl++;
        }
        while(cr < pr){
            int val = a[pr];
            int c = freq[val];
            counter[c]--;
            freq[val]--;
            counter[freq[val]]++;

            while(counter[pm] == 0) pm--;
            pr--;
        }

        ans[idx] = max(1, 2*pm - rng);
        // cout << idx << " " << pm << " " << rng << endl;
    }

    for(int i=1;i<=q;i++){
        cout << ans[i] << endl;
    }

}
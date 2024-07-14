#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int blk = sqrt(N) + 1;   // block size and total block will be sqrt(N)

struct query{

    public :
         int l,r,id;
         query() {}
         query(int l, int r, int id){
            this->l = l;
            this->r = r;
            this->id = id;
         }

         bool operator < (query cq){        // sort according to block then r
            if(l/blk != cq.l/blk) return l/blk < cq.l/blk;
            else return r < cq.r;
         }

};



int a[N],res[M];
query qu[M];
deque<int> freq[N];
set<pair<int,int>> freqs[N];

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        qu[i] = query(l, r, i);
    }

    sort(qu+1, qu+q+1);
    int prevl = 0, prevr = 0;             // keep trace of previous segment
    int prog = 0, dist = 0;

    for(int i=1;i<=q;i++){
        int curl = qu[i].l;
        int curr = qu[i].r;
        int idx = qu[i].id;

        while(curl < prevl){            // adding extra from left
            --prevl;
            int val = a[prevl];
            if(freq[val].size() > 0 and freqs[val].size() <= 1) prog--;
            if(freq[val].size() > 0) dist--;
            freq[val].push_front(prevl);
            if(freq[val].size() > 1){
                int diff = freq[val][1] - freq[val][0];
                auto it = freqs[val].lower_bound({diff, 0});
                if(it != freqs[val].end() and it->first == diff){
                    pair<int,int> temp = *it;
                    freqs[val].erase(it);
                    temp.second += 1;
                    freqs[val].insert(temp);
                } else{
                    freqs[val].insert({diff, 1});
                }
            }
            if(freq[val].size() > 0) dist++;
            if(freqs[val].size() <= 1) prog++;
        }
        while(prevr < curr){            // adding extra from right.
            ++prevr;
            int val = a[prevr];
            if(freq[val].size() > 0 and  freqs[val].size() <= 1) prog--;
            if(freq[val].size() > 0) dist--;
            freq[val].push_back(prevr);
            if(freq[val].size() > 1){
                int diff = freq[val][freq[val].size()-1] - freq[val][freq[val].size()-2];
                auto it = freqs[val].lower_bound({diff, 0});
                if(it != freqs[val].end() and it->first == diff){
                    pair<int,int> temp = *it;
                    freqs[val].erase(it);
                    temp.second += 1;
                    freqs[val].insert(temp);
                } else{
                    freqs[val].insert({diff, 1});
                }
            }
            if(freq[val].size() > 0) dist++;
            if(freqs[val].size() <= 1) prog++;
        }
        while(prevl < curl){            // removing extra from left.
            int val = a[prevl];
            if(freqs[val].size() <= 1) prog--;
            // freq[val].push_front(prevl);
            if(freq[val].size() > 1){
                int diff = freq[val][1] - freq[val][0];
                auto it = freqs[val].lower_bound({diff, 0});
                if(it != freqs[val].end()){
                    pair<int,int> temp = *it;
                    freqs[val].erase(it);
                    temp.second -= 1;
                    if(temp.second > 0) freqs[val].insert(temp);
                }
            }
            freq[val].pop_front();
            if(freq[val].size() == 0) dist--;
            if(freq[val].size() > 0 and freqs[val].size() <= 1) prog++;
            prevl++;
        }
        while(prevr > curr){            // removing extra from right.
            int val = a[prevr];
            if(freqs[val].size() <= 1) prog--;
            // freq[val].push_front(prevl);
            if(freq[val].size() > 1){
                int diff = freq[val][freq[val].size()-1] - freq[val][freq[val].size()-2];
                auto it = freqs[val].lower_bound({diff, 0});
                if(it != freqs[val].end()){
                    pair<int,int> temp = *it;
                    freqs[val].erase(it);
                    temp.second -= 1;
                    if(temp.second > 0) freqs[val].insert(temp);
                }
            }
            freq[val].pop_back();
            if(freq[val].size() == 0) dist--;
            if(freq[val].size() > 0 and freqs[val].size() <= 1) prog++;
            prevr--;
        }

        // cout << curl << " " << curr << " " << prog << " " << dist << endl;
        res[idx] = prog ? dist : dist + 1;

    }

    for(int i=1;i<=q;i++){
        cout << res[i] << endl;
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
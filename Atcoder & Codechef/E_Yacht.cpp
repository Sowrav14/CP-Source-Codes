#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

using Arr = array<int, 6>;

int dices[6];
// outcomes[d] = {counts, prob};
vector<vector<pair<Arr, double>>> outcomes;
int fact[6];

void build_outcomes() {
    fact[0] = 1;
    for(int i=1;i<6;i++) fact[i] = fact[i-1] * i;
    outcomes.assign(6, {});
    for(int d=0;d<=5;d++){
        Arr cnt; cnt.fill(0);
        function<void(int, int)> dfs = [&](int idx, int rem) -> void {
            if(idx == 5) {
                cnt[5] = rem;
                int ways = fact[d];
                for(int j=0;j<6;j++) ways /= fact[cnt[j]];
                double prob = (d == 0 ? 1.0 : ways / pow(6.0, d));
                outcomes[d].push_back({cnt, prob});
                return; 
            }
            for(int t=0;t<=rem;t++){
                cnt[idx] = t;
                dfs(idx + 1, rem - t);
            }
        };
        dfs(0, d);
    }
}
struct Key {
    Arr cnt;
    int rolls;
    bool operator==(Key const& o) const { return rolls==o.rolls && cnt==o.cnt; }
};
struct KeyHash {
    size_t operator()(Key const& k) const noexcept {
        size_t h = (size_t)k.rolls + 1469598103934665603ull;
        for(int i=0;i<6;i++) h = h * 1099511628211ull ^ (size_t)(k.cnt[i] + 1);
        return h;
    }
};

unordered_map<Key,double,KeyHash> memo;

double score_from_counts(const Arr &cnt){
    unordered_map<int,int> sum;
    for(int i=0;i<6;i++) sum[dices[i]] += cnt[i];
    double best = 0.0;
    for(auto &p: sum){
        best = max(best, (double)p.first * (double)p.second);
    }
    return best;
}

double solve_dp(const Arr &kept, int rolls_left){
    Key key{kept, rolls_left};
    auto it = memo.find(key);
    if(it!=memo.end()) return it->second;

    int kept_sum = 0;
    for(int i=0;i<6;i++) kept_sum += kept[i];
    int rem = 5 - kept_sum;
    double ans = 0.0;

    if(rolls_left == 0){
        ans = score_from_counts(kept);
    } else {
        const auto &outs = outcomes[rem];
        for(const auto &pr : outs){
            const Arr &obs = pr.first;
            double prob = pr.second;
            if(rolls_left == 1){
                Arr finalc;
                for(int i=0;i<6;i++) finalc[i] = kept[i] + obs[i];
                ans += prob * score_from_counts(finalc);
            } else {
                // choose subset of obs to keep (for each face choose 0..obs[i])
                double best_future = 0.0;
                Arr choice; choice.fill(0);
                function<void(int)> dfsKeep = [&](int idx){
                    if(idx==6){
                        Arr nk = kept;
                        for(int i=0;i<6;i++) nk[i] += choice[i];
                        double val = solve_dp(nk, rolls_left-1);
                        if(val > best_future) best_future = val;
                        return;
                    }
                    for(int t=0;t<=obs[idx]; ++t){
                        choice[idx]=t;
                        dfsKeep(idx+1);
                    }
                    choice[idx]=0;
                };
                dfsKeep(0);
                ans += prob * best_future;
            }
        }
    }

    memo.emplace(key, ans);
    return ans;
}

void solve(){

    for(int i=0;i<6;i++) cin >> dices[i];
    build_outcomes();
    Arr start; start.fill(0);
    double res = solve_dp(start, 3);

    cout.setf(std::ios::fixed);
    cout << setprecision(10) << res << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
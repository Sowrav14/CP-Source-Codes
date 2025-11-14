#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Algorithms implemented:
1) Greedy baseline:
   - For d = 1..D:
       pick type i maximizing s[d][i] - c[i] * (d - last[i])
     (last[i] is previous day type i used, or 0). This is a simple immediate-gain greedy.

2) Exact scoring and fast incremental updates:
   - Maintain for each type i a sorted set pos[i] of days it occurs, with sentinels 0 and D+1.
   - Penalty contribution for a gap of length L (L = next - prev - 1) is c[i] * f(L),
     where f(L) = L*(L+1)/2.
   - When moving a day d from type a to type b:
       compute prev_a, next_a, prev_b, next_b using pos sets
       compute penalty delta for a (removing d merges two gaps)
       compute penalty delta for b (inserting d splits one gap)
       compute score delta = s[d][b] - s[d][a] - penalty_change_a - penalty_change_b
     All computed in O(log D) time using set lower_bound.

3) Hill Climb (deterministic local search):
   - Try each day and each type; if an improving move exists (Δ > 0), apply it.
   - Continue until no immediate-improvement move found or iteration limit.

4) Simulated Annealing (stochastic local search):
   - Starting from current solution, propose random single-day changes (or occasional random swaps).
   - Use temperature schedule to accept worsening moves with probability exp(Δ / T).
   - Keep best found solution.

Why this is effective:
- Greedy gives a quick valid solution.
- Incremental scoring allows evaluating many local moves quickly (O(log D) each).
- Hill-climb refines deterministically to a local optimum.
- SA explores beyond local optima and often finds much better schedules.

Tuning notes:
- Time budget for SA is important. For local testing, keep small time (e.g., 0.8s).
- For contest runs, allocate most of allowed time to SA after quick hill-climb.
- Try different temperatures and move mixes (single change vs pair swap).

This file implements all the above and prints the best t[1..D].
*/

int D;
int c[27];
vector<vector<int>> svals; // svals[d][i] (1-indexed for d and i)
vector<int> tbest;

inline long long f_len(long long L){
    return L * (L + 1) / 2;
}

struct Solver {
    int D;
    int c[27];
    vector<vector<int>> s; // 1..D, 1..26
    vector<int> t; // 1..D current schedule
    vector< set<int> > pos; // 1..26 sets of days where type occurs, with sentinels 0 and D+1
    long long curScore;

    mt19937_64 rng;

    Solver(int D_, int carr[], const vector<vector<int>>& svals){
        D = D_;
        for(int i=1;i<=26;i++) c[i]=carr[i];
        s = svals;
        t.assign(D+1, 1);
        pos.assign(27, set<int>());
        rng.seed(chrono::high_resolution_clock::now().time_since_epoch().count());
    }

    // compute full penalty using pos sets (assumes pos built with sentinels)
    long long compute_penalty_total(){
        long long total = 0;
        for(int i=1;i<=26;i++){
            for(auto it = next(pos[i].begin()); it != pos[i].end(); ++it){
                int nextd = *it;
                auto pit = prev(it);
                int prevd = *pit;
                long long L = nextd - prevd - 1;
                if(L>0) total += c[i] * f_len(L);
            }
        }
        return total;
    }

    // compute full score from scratch for current t
    long long compute_full_score_from_t(){
        // build pos
        for(int i=1;i<=26;i++){
            pos[i].clear();
            pos[i].insert(0);
            pos[i].insert(D+1);
        }
        long long sumS = 0;
        for(int d=1; d<=D; ++d){
            pos[t[d]].insert(d);
            sumS += s[d][t[d]];
        }
        long long penalty = compute_penalty_total();
        return sumS - penalty;
    }

    // initialize greedy baseline
    void greedy_init(){
        // last occurrence for types
        vector<int> last(27, 0);
        for(int i=1;i<=26;i++){
            pos[i].clear();
            pos[i].insert(0);
            pos[i].insert(D+1);
        }
        for(int d=1; d<=D; ++d){
            int bestType = 1;
            long long bestVal = LLONG_MIN;
            for(int i=1;i<=26;i++){
                long long val = (long long)s[d][i] - (long long)c[i] * (d - last[i]);
                if(val > bestVal){
                    bestVal = val;
                    bestType = i;
                }
            }
            t[d] = bestType;
            last[bestType] = d;
            pos[bestType].insert(d);
        }
        curScore = compute_full_score_from_t();
    }

    // helper: get prev and next in set for given value x in pos[type]
    pair<int,int> prev_next(int type, int x){
        auto it = pos[type].lower_bound(x);
        if(it == pos[type].end()){
            // shouldn't happen because sentinel D+1 present
            int nxt = D+1;
            int prv = *prev(pos[type].end());
            return {prv, nxt};
        }
        if(*it == x){
            int nxt = *next(it);
            int prv = *prev(it);
            return {prv, nxt};
        } else {
            // it points to first element > x => nxt = *it, prv = *prev(it)
            int nxt = *it;
            int prv = *prev(it);
            return {prv, nxt};
        }
    }

    // compute delta score if we change day d from old = t[d] to newType
    long long delta_change_single(int d, int newType){
        int old = t[d];
        if(newType == old) return 0;
        // old removal: find prev and next of d in pos[old]
        auto it_old = pos[old].find(d);
        int prev_old = *prev(it_old);
        int next_old = *next(it_old);
        long long L1 = d - prev_old - 1;
        long long L2 = next_old - d - 1;
        long long Lnew = next_old - prev_old - 1;
        long long penalty_before_old = ( (L1>0? f_len(L1):0) + (L2>0? f_len(L2):0) ) * c[old];
        long long penalty_after_old = ( (Lnew>0? f_len(Lnew):0) ) * c[old];
        long long delta_penalty_old = penalty_after_old - penalty_before_old;
        // new insertion: find where d would be in pos[newType] => prev and next
        auto itn = pos[newType].lower_bound(d);
        int prev_new = *prev(itn);
        int next_new = *itn;
        long long Lbefore = next_new - prev_new - 1;
        long long Ln1 = d - prev_new - 1;
        long long Ln2 = next_new - d - 1;
        long long penalty_before_new = ( (Lbefore>0? f_len(Lbefore):0) ) * c[newType];
        long long penalty_after_new = ( ((Ln1>0? f_len(Ln1):0) + (Ln2>0? f_len(Ln2):0)) ) * c[newType];
        long long delta_penalty_new = penalty_after_new - penalty_before_new;
        long long deltaS = (long long)s[d][newType] - (long long)s[d][old] - (delta_penalty_old + delta_penalty_new);
        return deltaS;
    }

    // apply the change (assume newType != old) and update pos and curScore
    void apply_change_single(int d, int newType){
        int old = t[d];
        long long delta = delta_change_single(d, newType);
        // update sets
        pos[old].erase(d);
        pos[newType].insert(d);
        t[d] = newType;
        curScore += delta;
    }

    // hill-climb: try to improve by deterministic single-day changes
    void hill_climb_iter(int max_iter){
        bool improved = true;
        int iter = 0;
        vector<int> order(D);
        iota(order.begin(), order.end(), 1);
        while(improved && iter < max_iter){
            improved = false;
            shuffle(order.begin(), order.end(), rng);
            for(int idx = 0; idx < D; ++idx){
                int d = order[idx];
                int old = t[d];
                long long bestDelta = 0;
                int bestType = old;
                for(int nt=1; nt<=26; ++nt){
                    if(nt == old) continue;
                    long long delta = delta_change_single(d, nt);
                    if(delta > bestDelta){
                        bestDelta = delta;
                        bestType = nt;
                    }
                }
                if(bestType != old){
                    apply_change_single(d, bestType);
                    improved = true;
                }
            }
            ++iter;
        }
    }

    // Simulated annealing main loop: tries single-day random changes, accepts with prob
    void simulated_annealing(double time_budget_sec){
        auto t0 = chrono::high_resolution_clock::now();
        double TL = time_budget_sec;
        const int MAX_ITERS = 20000000;
        int it = 0;
        // parameters (tunable)
        double T0 = 2000.0;
        double T1 = 1e-4;
        uniform_int_distribution<int> day_dist(1, D);
        uniform_int_distribution<int> type_dist(1, 26);
        uniform_real_distribution<double> unit(0.0, 1.0);

        long long bestScoreLocal = curScore;
        vector<int> bestLocalT = t;

        while(true){
            ++it;
            auto now = chrono::high_resolution_clock::now();
            double elapsed = chrono::duration_cast<chrono::duration<double>>(now - t0).count();
            if(elapsed >= TL) break;
            double progress = elapsed / TL;
            double T = T0 * pow(T1 / T0, progress);

            // candidate move: with high prob, single-day change; occasionally try swap two days
            int d = day_dist(rng);
            int newType = type_dist(rng);
            int old = t[d];
            if(newType == old){
                continue;
            }
            long long delta = delta_change_single(d, newType);
            bool accept = false;
            if(delta >= 0) accept = true;
            else {
                double prob = exp((double)delta / T);
                if(unit(rng) < prob) accept = true;
            }
            if(accept){
                apply_change_single(d, newType);
                if(curScore > bestScoreLocal){
                    bestScoreLocal = curScore;
                    bestLocalT = t;
                }
            }
        }

        // adopt best local found
        t = bestLocalT;
        // rebuild pos and curScore from it
        curScore = compute_full_score_from_t();
    }

};

void solve(){
    // read input
    cin >> D;
    for(int i=1;i<=26;i++) cin >> c[i];
    svals.assign(D+1, vector<int>(27,0));
    for(int d=1; d<=D; ++d){
        for(int i=1;i<=26;i++){
            cin >> svals[d][i];
        }
    }

    Solver solver(D, c, svals);
    // 1) greedy baseline
    solver.greedy_init();
    // 2) quick hill-climb deterministic
    solver.hill_climb_iter(5); // 5 outer passes (tunable)
    // 3) simulated annealing: give a time budget (seconds)
    double time_budget = 1.8; // seconds: adjust for contest environment; increase if you have more time
    solver.simulated_annealing(time_budget);
    // 4) final local polish
    solver.hill_climb_iter(3);

    // output best schedule
    for(int d=1; d<=D; ++d){
        cout << solver.t[d] << "\n";
    }
}

signed main(){
    Fast_IO()
    int t = 1;
    for(int i=1;i<=t;i++){
        solve();
    }
}

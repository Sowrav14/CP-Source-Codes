#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

/*
Approach (brief):
- We maintain the elements of the processed prefix in their sorted positions.
- pos[i] = rank (1-based) of A[i] in the full-array-sorted-by-(value,then-index).
- We maintain two Fenwick trees (BIT): one for counts and one for sums over sorted positions.
- As we activate A[i] (when extending prefix), we add count +1 at pos[i] and sum += A[i] at pos[i].
- For the "min + best suffix" case:
  * Let r = total active count, min = 1st active element (find_kth(1)).
  * We binary-search over rank i in [1..r-1] (index among active elements) to find largest i
    such that value_at_rank_i <= mean(min + sum of active elements with rank > i).
  * After finding boundary, compute the subsequence (min + suffix starting at rank i+1),
    compute integer mean = floor(sum/(size)), compute f for that subsequence.
- For the "max + best prefix" case:
  * Symmetric: let max = r-th active element, binary-search smallest j in [2..r]
    such that value_at_rank_j >= mean(max + sum of active elements with rank < j).
  * Then subsequence is (prefix ranks 1..j-1) + max.
- For each prefix we compute both cases and print the larger f.
- All needed operations (find_kth by rank, prefix sums) are done by Fenwick trees.
Time: O(N log^2 N) worst-case (binary-search * find_kth/sum), fits constraints.
*/

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick() {}
    Fenwick(int _n) {init(_n);}
    void init(int _n){ n = _n; bit.assign(n+1,0); }
    void add(int idx, long long val){
        for(; idx<=n; idx += idx&-idx) bit[idx] += val;
    }
    long long sumPrefix(int idx){
        long long res = 0;
        for(; idx>0; idx -= idx&-idx) res += bit[idx];
        return res;
    }
    long long sumRange(int l, int r){
        if(r < l) return 0;
        return sumPrefix(r) - sumPrefix(l-1);
    }
    // find smallest index idx such that prefix sum >= k (k >= 1)
    int find_kth(long long k){
        if(k <= 0) return 0;
        int idx = 0;
        int LOG = 1;
        while((1<<LOG) <= n) LOG++;
        for(int i = LOG; i>=0; --i){
            int next = idx + (1<<i);
            if(next <= n && bit[next] < k){
                idx = next;
                k -= bit[next];
            }
        }
        return idx + 1;
    }
};

int solve_min_case(Fenwick &cntBIT, Fenwick &sumBIT, int total_count, vector<int> &val_at_pos){
    if(total_count == 0) return 0;
    if(total_count == 1) return 0;
    // min element:
    int min_pos = cntBIT.find_kth(1);
    long long min_val = val_at_pos[min_pos];
    long long total_sum = sumBIT.sumPrefix(sumBIT.n);
    int r = total_count;
    int lo = 1, hi = r-1, best_i = 0; // we search for largest i in [1..r-1]
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int pos_mid = cntBIT.find_kth(mid);
        long long val_mid = val_at_pos[pos_mid];
        long long sum_prefix_mid = sumBIT.sumPrefix(pos_mid);
        long long sum_suffix = total_sum - sum_prefix_mid; // ranks > mid
        int cnt_suffix = r - mid;
        long double mean = ( (long double)min_val + (long double)sum_suffix ) / ( (long double)(cnt_suffix + 1) );
        if((long double)val_mid <= mean){
            best_i = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    // chosen suffix starts at rank (best_i + 1)
    int start_rank = best_i + 1;
    if(start_rank > r){ // no suffix, only min
        return 0;
    }
    int pos_start = cntBIT.find_kth(start_rank);
    long long sum_prefix_before = sumBIT.sumPrefix(cntBIT.find_kth(best_i)) ; // if best_i==0, this will find_kth(0) which returns 0; handle:
    if(best_i == 0) sum_prefix_before = 0;
    // sum of suffix:
    long long sum_suffix_final = total_sum - sum_prefix_before;
    int cnt_suffix_final = r - best_i;
    int total_elems = cnt_suffix_final + 1;
    long long sum_total = min_val + sum_suffix_final;
    long long integer_mean = sum_total / total_elems;
    // max in selected is the largest active element (rank r)
    int pos_r = cntBIT.find_kth(r);
    long long max_selected = val_at_pos[pos_r];
    long long f_case = max( llabs(integer_mean - min_val), llabs(max_selected - integer_mean) );
    return (int)f_case;
}

int solve_max_case(Fenwick &cntBIT, Fenwick &sumBIT, int total_count, vector<int> &val_at_pos){
    if(total_count == 0) return 0;
    if(total_count == 1) return 0;
    int r = total_count;
    int pos_r = cntBIT.find_kth(r);
    long long max_val = val_at_pos[pos_r];
    long long total_sum = sumBIT.sumPrefix(sumBIT.n);
    // Binary search smallest j in [2..r] such that value_at_rank_j >= mean(max + sum ranks < j)
    int lo = 2, hi = r, best_j = r+1; // best_j will be minimal j satisfying condition, if any
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int pos_mid = cntBIT.find_kth(mid);
        long long val_mid = val_at_pos[pos_mid];
        // sum of first mid-1 elements:
        int pos_mid_elem = pos_mid;
        long long sum_first_mid = sumBIT.sumPrefix(pos_mid_elem); // sum of first mid active elements
        // value of mid-th element:
        long long val_midth = val_mid;
        long long sum_first_mid_minus1 = sum_first_mid - val_midth;
        int cnt_first = mid - 1;
        long double mean = ( (long double)max_val + (long double)sum_first_mid_minus1 ) / ( (long double)(cnt_first + 1) );
        if((long double)val_mid >= mean){
            best_j = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    int chosen_prefix_count;
    long long sum_prefix_final;
    if(best_j == r+1){
        // no j satisfied, best is just max alone (no prefix elements included)
        chosen_prefix_count = 0;
        sum_prefix_final = 0;
    } else {
        chosen_prefix_count = best_j - 1; // ranks 1..best_j-1 included
        int pos_prev = cntBIT.find_kth(chosen_prefix_count); // if chosen_prefix_count==0, find_kth(0) invalid -> handle
        if(chosen_prefix_count == 0) sum_prefix_final = 0;
        else sum_prefix_final = sumBIT.sumPrefix(pos_prev);
    }
    int total_elems = chosen_prefix_count + 1;
    long long sum_total = max_val + sum_prefix_final;
    long long integer_mean = sum_total / total_elems;
    int pos_1 = cntBIT.find_kth(1);
    long long min_selected = val_at_pos[pos_1];
    long long f_case = max( llabs(max_val - integer_mean), llabs(integer_mean - min_selected) );
    return (int)f_case;
}

void solve(){

    int t;
    if(!(cin >> t)) return;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=1;i<=n;i++) cin >> A[i];
        // build pos array (rank by value, tie by index)
        vector<pair<int,int>> vp;
        vp.reserve(n);
        for(int i=1;i<=n;i++) vp.push_back({A[i], i});
        sort(vp.begin(), vp.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        vector<int> pos(n+1);
        vector<int> val_at_pos(n+1); // 1-based
        for(int i=0;i<n;i++){
            int rank = i+1;
            pos[vp[i].second] = rank;
            val_at_pos[rank] = vp[i].first;
        }
        Fenwick cntBIT, sumBIT;
        cntBIT.init(n);
        sumBIT.init(n);
        int total_count = 0;
        long long total_sum = 0;
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            int p = pos[i];
            cntBIT.add(p, 1);
            sumBIT.add(p, A[i]);
            total_count += 1;
            total_sum += A[i];
            int res1 = solve_min_case(cntBIT, sumBIT, total_count, val_at_pos);
            int res2 = solve_max_case(cntBIT, sumBIT, total_count, val_at_pos);
            ans[i] = max(res1, res2);
        }
        for(int i=1;i<=n;i++){
            if(i>1) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
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

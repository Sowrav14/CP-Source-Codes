class Solution {
public:
    const int MOD = 1e9 + 7;

    class Fenwick {
    public:
        vector<long long> tree;
        int sz;
        Fenwick(int n) : sz(n + 1), tree(n + 2, 0) {}
        void update(int idx, long long val) {
            val %= MOD;
            if (val < 0) val += MOD;
            idx++;
            while (idx <= sz) {
                tree[idx] = (tree[idx] + val) % MOD;
                idx += idx & -idx;
            }
        }
        long long query(int idx) {
            long long res = 0;
            idx++;
            while (idx > 0) {
                res = (res + tree[idx]) % MOD;
                idx -= idx & -idx;
            }
            return res;
        }
        long long query(int l, int r) {
            if (l > r) return 0;
            return (query(r) - query(l - 1) + MOD) % MOD;
        }
    };

    vector<int> get_divisors(int x) {
        vector<int> res;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                res.push_back(i);
                if (i != x / i) res.push_back(x / i);
            }
        }
        return res;
    }

    vector<int> compute_mu(int max_val) {
        vector<int> mu(max_val + 1, 1);
        vector<bool> is_prime(max_val + 1, true);
        for (int i = 2; i <= max_val; ++i) {
            if (is_prime[i]) {
                mu[i] = -1; 
                for (int j = i * 2; j <= max_val; j += i) {
                    is_prime[j] = false;
                    mu[j] *= -1;
                }
                for (long long j = (long long)i * i; j <= max_val; j += i * i) {
                    mu[j] = 0;
                }
            }
        }
        mu[1] = 1;
        return mu;
    }

    long long compute_f(const vector<int>& S, int max_val) {
        if (S.empty()) return 0;
        set<int> unique_vals(S.begin(), S.end());
        vector<int> ranks(unique_vals.begin(), unique_vals.end());
        int num_unique = ranks.size();
        unordered_map<int, int> rank_map;
        for (int k = 0; k < num_unique; ++k) {
            rank_map[ranks[k]] = k + 1;
        }
        Fenwick ft(num_unique);
        long long total = 0;
        for (int val : S) {
            int r = rank_map[val];
            long long q = ft.query(1, r - 1);
            long long curr = (1 + q) % MOD;
            ft.update(r, curr);
            total = (total + curr) % MOD;
        }
        return total;
    }

    int totalBeauty(vector<int>& nums) {
        vector<int> talvirekos = nums;
        int n = talvirekos.size();
        int max_val = *max_element(talvirekos.begin(), talvirekos.end());

        unordered_map<int, vector<int>> d_to_s;
        for (int x : talvirekos) {
            vector<int> divs = get_divisors(x);
            for (int d : divs) {
                d_to_s[d].push_back(x);
            }
        }

        vector<int> mu = compute_mu(max_val);

        long long ans = 0;
        for (auto& p : d_to_s) {
            int d = p.first;
            vector<int>& S = p.second;
            sort(S.begin(), S.end());
            long long f_d = compute_f(S, max_val);
            long long beauty = 0;
            vector<int> divs = get_divisors(d);
            for (int k : divs) {
                if (d_to_s.count(k)) {
                    beauty = (beauty + (long long)mu[k] * compute_f(d_to_s[k], max_val)) % MOD;
                    if (beauty < 0) beauty += MOD;
                }
            }
            ans = (ans + (long long)d * beauty % MOD) % MOD;
        }

        return ans;
    }
};
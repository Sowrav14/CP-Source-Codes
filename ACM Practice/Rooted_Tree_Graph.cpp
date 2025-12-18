#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {

        // storing the input midway as required
        auto dalmerinth = nums;  // <-- REQUIRED VARIABLE

        int n = nums.size();
        
        // Precompute nums_mod = nums[i] % k
        vector<int> modv(n);
        for (int i = 0; i < n; i++)
            modv[i] = nums[i] % k;

        // prefix hash to check modulo consistency
        vector<int> pref(n+1);
        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + (modv[i] == modv[0] ? 1 : 0);

        // actually need prefix per mod:
        unordered_map<int, vector<int>> modPos;
        for (int i = 0; i < n; i++)
            modPos[modv[i]].push_back(i);

        vector<long long> ans;
        ans.reserve(queries.size());

        // preprocess adjusted values t_i = nums[i] / k (floor)
        vector<long long> t(n);
        for (int i = 0; i < n; i++) t[i] = nums[i] / k;

        // prefix sums for each mod bucket (for fast sum query)
        // but since mod bucket sizes vary, we store prefix sums on the fly
        unordered_map<int, vector<long long>> prefT;
        for (auto &p : modPos) {
            int md = p.first;
            auto &vec = p.second;
            prefT[md].resize(vec.size()+1);
            for (int i = 0; i < (int)vec.size(); i++)
                prefT[md][i+1] = prefT[md][i] + t[vec[i]];
        }

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int md = modv[l];

            // check if all nums[x] ≡ nums[l] (mod k)
            auto &v = modPos[md];
            auto &pT = prefT[md];

            // find count of indices in [l, r]
            int L = lower_bound(v.begin(), v.end(), l) - v.begin();
            int R = upper_bound(v.begin(), v.end(), r) - v.begin();

            if (R - L != (r - l + 1)) {
                ans.push_back(-1);
                continue;
            }

            // extract t_i in the range; use prefix sums
            int len = R - L;
            long long sumT = pT[R] - pT[L];

            // median index
            int midIdx = L + len/2;
            long long medianT = t[v[midIdx]];

            // compute total cost = sum |t_i - medianT|
            long long cost = 0;
            // left part
            long long leftSum = pT[midIdx] - pT[L];
            cost += medianT * (midIdx - L) - leftSum;

            // right part
            long long rightSum = pT[R] - pT[midIdx+1];
            cost += rightSum - medianT * (R - (midIdx+1));

            ans.push_back(cost);
        }

        return ans;
    }
};

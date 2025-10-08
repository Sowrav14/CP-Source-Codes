#include <bits/stdc++.h>
using namespace std;

/*
Burnside’s Lemma for cube face colorings:
-----------------------------------------
We want the number of distinct cube paintings with given multiset of 6 face colors,
modulo the cube’s 24 rotation symmetries.

The group has 24 elements in 5 classes:
 1) Identity (1 element): 6 cycles of length 1
 2) Face 90° (6 elements): cycles = 4+1+1
 3) Face 180° (3 elements): cycles = 2+2+1+1
 4) Vertex 120° (8 elements): cycles = 3+3
 5) Edge 180° (6 elements): cycles = 2+2+2

For each class, we count how many colorings remain fixed,
then average over 24.
*/


// ---------- Helper: multinomial coefficient ----------------
// multinomial(n; m1,m2,...) = n! / (m1! * m2! * ...)
// Here used for assigning distinguishable cycles.
long long multinomial(int total, const vector<int> &parts) {
    long long res = 1;
    int n = total;
    for (int m : parts) {
        for (int k = 1; k <= m; k++) {
            res *= n;
            res /= k;
            n--;
        }
    }
    return res;
}

// ---------- Identity rotation ----------
// All permutations of faces using exactly the counts.
// Count = 6! / (prod m_c!).
long long fixed_identity(const vector<int> &m) {
    return multinomial(6, m);
}

// ---------- Face 90° rotation ----------
// Cycles: (4)(1)(1)
// Choose a color with >=4 copies for the 4-cycle, reduce its count by 4.
// Remaining 2 faces (distinguishable) filled with the reduced multiset.
// Count = sum_{c: m_c>=4} [ 2! / prod(m'_c!) ].
long long fixed_face90(const vector<int> &m) {
    long long total = 0;
    for (int c = 0; c < (int)m.size(); c++) {
        if (m[c] >= 4) {
            vector<int> m2 = m;
            m2[c] -= 4;
            total += multinomial(2, m2);
        }
    }
    return total;
}

// ---------- Face 180° rotation ----------
// Cycles: (2)(2)(1)(1)
// Need assignment of two 2-cycles and two 1-cycles.
// Equivalent to choosing k_c^(2), k_c^(1) s.t. 2*k_c^(2)+k_c^(1)=m_c,
// sum k_c^(2)=2, sum k_c^(1)=2.
// Count = sum over valid { 2! / prod k_c^(2)! * 2! / prod k_c^(1)! }.
long long fixed_face180(const vector<int> &m) {
    long long total = 0;
    int C = m.size();
    // Try all splits of counts into pairs and singles
    // For small C (<=6) this is cheap.
    function<void(int,int,int,vector<int>,vector<int>)> dfs =
    [&](int idx, int pairsLeft, int singlesLeft, vector<int> k2, vector<int> k1) {
        if (idx == C) {
            if (pairsLeft==0 && singlesLeft==0) {
                // Check condition: 2*k2[i]+k1[i] = m[i]
                for (int i=0;i<C;i++) {
                    if (2*k2[i]+k1[i] != m[i]) return;
                }
                // count ways
                long long ways = multinomial(2,k2)*multinomial(2,k1);
                total += ways;
            }
            return;
        }
        for (int a=0;a<=pairsLeft;a++) {
            for (int b=0;b<=singlesLeft;b++) {
                if (2*a+b > m[idx]) continue;
                k2[idx]=a; k1[idx]=b;
                dfs(idx+1,pairsLeft-a,singlesLeft-b,k2,k1);
            }
        }
    };
    dfs(0,2,2,vector<int>(C),vector<int>(C));
    return total;
}

// ---------- Vertex 120° rotation ----------
// Cycles: (3)(3)
// Need counts divisible by 3. Assign two 3-cycles (distinguishable).
// Condition: each m_c = 3*k_c, sum k_c=2.
// Count = multinomial(2, {k_c}).
long long fixed_vertex120(const vector<int> &m) {
    vector<int> k(m.size());
    int sum=0;
    for (int i=0;i<(int)m.size();i++) {
        if (m[i]%3!=0) return 0;
        k[i]=m[i]/3;
        sum+=k[i];
    }
    if (sum!=2) return 0;
    return multinomial(2,k);
}

// ---------- Edge 180° rotation ----------
// Cycles: (2)(2)(2)
// Need counts even. m_c = 2*k_c. sum k_c=3.
// Count = multinomial(3,{k_c}).
long long fixed_edge180(const vector<int> &m) {
    vector<int> k(m.size());
    int sum=0;
    for (int i=0;i<(int)m.size();i++) {
        if (m[i]%2!=0) return 0;
        k[i]=m[i]/2;
        sum+=k[i];
    }
    if (sum!=3) return 0;
    return multinomial(3,k);
}

// ---------- Main function: Burnside average ----------
long long distinct_paintings(const vector<int> &m) {
    long long total = 0;
    total += fixed_identity(m);              // 1 element
    total += 6*fixed_face90(m);              // 6 elements
    total += 3*fixed_face180(m);             // 3 elements
    total += 8*fixed_vertex120(m);           // 8 elements
    total += 6*fixed_edge180(m);             // 6 elements
    return total/24;
}

/*
Example usage:

Input: vector<int> counts(6);
Suppose we have colors: 4 white, 2 red, rest 0.
counts = {4,2,0,0,0,0};

cout << distinct_paintings(counts) << endl; // Output: 2

Explanation: There are 2 distinct cube paintings with 4 W and 2 R.
*/


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        map<char,int> m;
        for(int i=0;i<6;i++){
            char c; cin >> c;
            m[c]++;
        }
        vector<int> cnt;
        for(auto i : m) cnt.push_back(i.second);
        while(cnt.size() != 6) cnt.push_back(0);
        cout << distinct_paintings(cnt) << endl;
    }

    return 0;
}

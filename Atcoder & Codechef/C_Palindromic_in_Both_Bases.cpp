#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

// Function to check if a vector is a palindrome
bool is_palindrome(const vector<int>& digits) {
    int l = 0, r = digits.size() - 1;
    while (l < r) {
        if (digits[l] != digits[r]) return false;
        l++, r--;
    }
    return true;
}

// Convert x to base-a and return digits
vector<int> to_base(int x, int a) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % a);
        x /= a;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int A, N;
    cin >> A >> N;

    int ans = 0;
    // Even length
    for (int half = 1; ; ++half) {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());
        string pal = s + rev;
        int num = stoll(pal);
        if (num > N) break;
        if (is_palindrome(to_base(num, A))) {
            ans += num;
        }
    }

    // Odd length
    for (int half = 1; ; ++half) {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());
        rev = rev.substr(1);
        string pal = s + rev;
        int num = stoll(pal);
        if (num > N) break;
        if (is_palindrome(to_base(num, A))) {
            ans += num;
        }
    }

    cout << ans << '\n';
}

signed main() {
    Fast_IO()
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}

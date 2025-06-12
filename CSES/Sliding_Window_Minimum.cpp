#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++)
        arr[i] = (1LL * a * arr[i - 1] + b) % c;
    deque<int> dq;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && arr[dq.back()] >= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1)
            res ^= arr[dq.front()];
    }
    cout << res << '\n';
}

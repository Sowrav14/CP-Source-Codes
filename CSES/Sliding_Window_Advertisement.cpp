#include <bits/stdc++.h>
using namespace std;

vector<long long> compute_max_areas(const vector<long long>& heights, int n, int k) {
    vector<long long> results(n - k + 1);
    vector<int> left(n), right(n);
    stack<int> s;
    
    // Compute left boundaries
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    
    // Compute right boundaries
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }
    
    // For each window position, store events: (window_start, area)
    vector<vector<pair<int, long long>>> events(n + 1);
    for (int i = 0; i < n; i++) {
        // For each board i, compute the windows where it contributes
        int earliest_window = max(0, right[i] - k + 1); // First window where right[i] is in
        int latest_window = left[i]; // Last window where left[i] is in
        for (int w = 1; w <= k && left[i] + w - 1 <= right[i]; w++) {
            long long area = heights[i] * w;
            int window_start = left[i];
            int window_end = min(right[i] - w + 1, n - k);
            if (window_start <= window_end) {
                events[window_start].emplace_back(window_start, area);
                if (window_end + 1 <= n) {
                    events[window_end + 1].emplace_back(window_start, 0); // Remove area
                }
            }
        }
    }
    
    // Process windows using a multiset to track active areas
    multiset<long long> active_areas;
    for (int i = 0; i <= n - k; i++) {
        // Add new areas
        for (auto [window, area] : events[i]) {
            if (area > 0) {
                active_areas.insert(area);
            } else {
                active_areas.erase(active_areas.find(events[window][0].second));
            }
        }
        results[i] = active_areas.empty() ? 0 : *active_areas.rbegin();
    }
    
    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    vector<long long> results = compute_max_areas(heights, n, k);
    
    // Output results
    for (int i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i < results.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
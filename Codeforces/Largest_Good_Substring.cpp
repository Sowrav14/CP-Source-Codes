#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    int m = s.length();

    vector<int> min_end(m, m); 

    for (int i = 0; i < n; i++) {
        string bad;
        cin >> bad;
        
        size_t pos = s.find(bad, 0);
        while (pos != string::npos) {

            int end_pos = pos + bad.length() - 1;
            min_end[pos] = min(min_end[pos], end_pos);
            pos = s.find(bad, pos + 1);
        }
    }


    for (int i = m - 2; i >= 0; i--) {
        min_end[i] = min(min_end[i], min_end[i + 1]);
    }

    int max_len = 0;
    for (int i = 0; i < m; i++) {
        int current_len = min_end[i] - i;
        max_len = max(max_len, current_len);
    }

    cout << max_len << endl;

    return 0;
}
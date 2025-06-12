#include<bits/stdc++.h>
using namespace std;

void checkDuplicatesInRange(const vector<int>& arr, int l, int r) {
    unordered_map<int, int> frequency;
    
    for (int i = l; i <= r; i++) {
        frequency[arr[i]]++;
        if (frequency[arr[i]] > 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

void solve() {
    int n, q;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        checkDuplicatesInRange(arr, l, r);
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
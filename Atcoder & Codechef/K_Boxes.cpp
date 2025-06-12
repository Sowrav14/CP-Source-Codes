#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

struct Theif {
    int i, a, b;
    Theif() : i(0), a(0), b(0) {}
    Theif(int i_, int a_, int b_) : i(i_), a(a_), b(b_) {}
    bool operator<(const Theif& other) const {
        if (a != other.a) return a < other.a;
        if (b != other.b) return b < other.b;
        return i < other.i;
    }
};

void solve(){

    int n, k; cin >> n >> k;
    vector<Theif> theifs(n);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        theifs[i].i = i;
        theifs[i].a = a;
    }
    for(int i=0;i<n;i++){
        int b; cin >> b;
        theifs[i].b = b;
    }
    sort(theifs.begin(), theifs.end());

    priority_queue<int, vector<int>, greater<int>> window;
    int window_sum = 0;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int id = theifs[i].i;
        int a = theifs[i].a;
        int b = theifs[i].b;

        ans[id] = window_sum;

        if(window.size() < k) {
            window.push(b);
            window_sum += b;
        } else if (!window.empty() && b > window.top()) {
            window_sum -= window.top();
            window.pop();
            window.push(b);
            window_sum += b;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    } cout << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
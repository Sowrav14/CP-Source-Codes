#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

    int k, n, m; cin >> k >> n >> m;;
    priority_queue<int> a1, a2;
    priority_queue<int> b1, b2;
    int z = 0;
    int zz = 0;

    for(int i=1;i<=n;i++){
        int x; cin >> x;
        if(x > 0) a1.push(x);
        else b1.push(-x);
    }

    for(int i=1;i<=m;i++){
        int x; cin >> x;
        if(x > 0) a2.push(x);
        else if(x < 0) b2.push(-x);
        else z++;
    }

    
    // vector<int> great;
    int ans = 0;
    while(!a1.empty() and !a2.empty()){
        if(k == 0) break;
        ans += (a1.top() * a2.top());
        a1.pop(), a2.pop();
        k--;
    }

    while(!b1.empty() and !b2.empty()){
        if(k == 0) break;
        ans += (b1.top() * b2.top());
        b1.pop(), b2.pop();
        k--;
    }

    while(!a1.empty() and !b1.empty() and z){
        if(k == 0) break;
        k--;
        ans += (0);
        if(a1.top() > b1.top()){
            a1.pop();
        } else {
            b1.pop();
        }
        z--;
    }
    while(!a2.empty() and !b2.empty() and z){
        if(k == 0) break;
        k--;
        ans += (0);
        if(a2.top() > b2.top()){
            a2.pop();
        } else {
            b2.pop();
        }
        zz--;
    }
    vector<int> xx, yy, x, y;
    while(!a1.empty()){
        xx.push_back(a1.top());
        a1.pop();
    }
    while(!b1.empty()){
        yy.push_back(b1.top());
        b1.pop();
    }
    while(!a2.empty()){
        x.push_back(a2.top());
        a2.pop();
    }
    while(!b2.empty()){
        y.push_back(b2.top());
        b2.pop();
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    // for(auto i : y) cout << i << " "; cout << endl;
    // for(auto i : xx) cout << i << " "; cout << endl;
    int i = 0;
    while(i < xx.size() and k > 0 and y.size() >= k){
        ans -= (xx[i] * y[k-1]);
        k--;
        i++;
    }

    int j = 0;
    while(j < yy.size() and k > 0 and x.size() >= k){
        ans -= (yy[j] * x[k-1]);
        k--;
        j++;
    }

    // for(auto i : great) cout << i << " "; cout << endl;

    // sort(great.rbegin(), great.rend());

    // int ans = 0;
    // for(int i=0;i<min(k, (long long)great.size());i++){
    //     ans += great[i];
    // }
    cout << ans << endl;


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
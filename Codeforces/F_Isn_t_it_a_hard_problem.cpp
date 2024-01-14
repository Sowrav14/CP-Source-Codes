#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 5*1e5 + 10;
int a[N];
int tree[4*N];
void build(int node, int l, int r){

    if(l == r){
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = max(tree[2*node], tree[2*node + 1]);

}

int query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return INT_MIN;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right = query(2*node+1, mid+1, r, i, j);
    return max(left,right);
}



void solve(){

    int n,k; cin >> n >> k;
    vector<int>er(n), val(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int sz = s.size();
        int temp = 0;
        for(int j=0;j<sz/2;j++){
            if(s[j] != s[sz-j-1]) temp++;
        }
        er[i] = temp;
    }
    for(int i=0;i<n;i++) cin >> val[i];

    // for(int i=0;i<n;i++) cout << er[i] << " "; cout << endl;
    // for(int i=0;i<n;i++) cout << val[i] << " "; cout << endl;

    vector<int>prefer(n+1,0);

    for(int i=1;i<=n;i++){
        prefer[i] = prefer[i-1] + er[i-1];
        a[i] = a[i-1] + val[i-1];
    }

    // for(int i=1;i<=n;i++) cout << prefer[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << a[i] << " "; cout << endl;

    build(1, 1, n);
    // cout << query(1, 1, n, 1, 3) << endl;
    int ans = 0;
    for(int i=0;i<=n;i++){
        int cur = prefer[i];
        int mx = cur + k;
        int idx = upper_bound(prefer.begin(), prefer.end(), mx) - prefer.begin();
        if(prefer[idx] - prefer[i] > k) idx--;

        int mxval = query(1, 1, n, i+1, idx);
        // cout << i << " " << idx << " " << mxval << " " << mxval - a[i] << endl;
        ans = max(ans, mxval - a[i]);
    }

    cout << ans << endl;


}


signed main(){
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
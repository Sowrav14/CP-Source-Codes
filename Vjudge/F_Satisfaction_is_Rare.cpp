#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5+10;
pair<int,int> a[N];
int tree[4*N];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = a[l].second;
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = max(tree[2*node], tree[2*node + 1]);

}



int query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return 0;
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right = query(2*node+1, mid+1, r, i, j);
    return max(left, right);
}



void solve(){

    int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+n+1, greater<pair<int,int>>());
    vector<int>pref(n+1, -1);
    stack<pair<int,int>>st;
    st.push({-1, -1});
    for(int i=1;i<=n;i++){
        while(!st.empty()){
            if(a[i].first != st.top().first){
                pref[i] = st.top().second;
                break;
            }
            st.pop();
        }
        st.push({a[i].first, i});
    }
    build(1, 1, n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int r = pref[i];
        if(pref[i] == -1) continue;
        int mx = query(1, 1, n, 1, r);
        // cout << a[i].first << " " << a[i].second << " " << pref[i] << " " << mx << endl;
        if(mx > a[i].second) ans++;
    }
    cout << n - ans << endl;

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 5e5 + 10;
const int M = 998244353;
const int inf = 1e12;

int f[N];
int a[N];

int tree[4*N];

void build(int node, int start, int end){
  if(start == end){
    tree[node] = a[start];
    return;
  }
  int mid = (start + end) / 2;
  build(2*node, start, mid);
  build(2*node+1, mid+1, end);
  tree[node] = tree[2*node] + tree[2*node+1];
  tree[node] %= M;
}

void update(int node, int start, int end, int idx, int val){
  if(start == end){
    tree[node] = val;
    return;
  }
  int mid = (start + end) / 2;
  if(idx <= mid){
    update(2*node, start, mid, idx, val);
  } else {
    update(2*node+1, mid+1, end, idx, val);
  }
  tree[node] = tree[2*node] + tree[2*node+1];
  tree[node] %= M;
}

int query(int node, int start, int end, int l, int r){
  if(r < start or end < l) return 0;
  if(l <= start and end <= r) return tree[node];
  int mid = (start + end) / 2;
  int p1 = query(2*node, start, mid, l, r);
  int p2 = query(2*node+1, mid+1, end, l, r);
  return (p1 + p2) % M;
}

void fact(){
  f[0] = 1;
  for(int i=1;i<N;i++){
    f[i] = (f[i - 1] * i) % M;
  }
}

int p[N][10];
void precal(){
  for(int i=0;i<10;i++) p[0][i] = 1;
  for(int i=0;i<10;i++) p[1][i] = 1;
  for(int i=0;i<10;i++) p[2][i] = 2;
  p[3][0] = 3; p[3][1] = 6; p[3][2] = 720; p[3][3] = f[720];
  p[4][0] = 4; p[4][1] = 24; p[4][2] = f[24];
  p[5][0] = 5; p[5][1] = 120; p[5][2] = f[120];
  p[6][0] = 6; p[6][1] = 720; p[6][2] = f[720];
  p[7][0] = 7; p[7][1] = 5040; p[7][2] = f[5040];
  p[8][0] = 8; p[8][1] = 40320; p[8][2] = f[40320];
  p[9][0] = 9; p[9][1] = 362880; p[9][2] = f[362880];
  p[10][0] = 10; p[10][1] = 3628800; p[10][2] = 821984089;
  p[11][0] = 11; p[11][1] = 39916800; p[11][2] = 644056242;
  p[12][0] = 12; p[12][1] = 479001600; p[12][2] = 527656359;
  for(int i=13;i<N;i++){
    p[i][0] = i;
    p[i][1] = f[i];
  }
}


void solve(){

  int n, q; cin >> n >> q;
  for(int i=1;i<=n;i++) cin >> a[i];
  
  build(1, 1, n);

  vector<int> cnt(n+1, 0);
  set<int> s;
  for(int i=1;i<=n;i++) s.insert(i);
  // cout << s.size() << endl;

  while(q--){
    int t; cin >> t;
    if(t == 1){
      int l, r; cin >> l >> r;
      auto it = s.lower_bound(l);
      while(it != s.end() and *it <= r){
        // cout << "Processing index: " << *it << endl; // Debug line
        int idx = *it;
        int val = a[idx];
        cnt[idx]++;
        
        if(cnt[idx] < 10){
          // cout << "Updating index " << idx << " from " << val << " to " << p[val][cnt[idx]] << endl; // Debug line
          update(1, 1, n, idx, p[val][cnt[idx]]);
        } else {
          // Once cnt[idx] reaches 10, we stop updating this index
          it = s.erase(it); // Remove from set and get next iterator
          continue; // Skip the increment of iterator below
        }
        it++;
      }
    } else {
      int l, r; cin >> l >> r;
      int ans = query(1, 1, n, l, r);
      cout << ans << endl;
    }
  }

}


signed main(){
  Fast_IO()
  fact();
  precal();
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      // cout << "Case #" << i << ": ";
      solve();
  }
}
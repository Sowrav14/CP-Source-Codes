#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 1e6 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int a[N];
pair<int,int> tree[4*N];
int lazy[4*N];

void pull(int n){
  tree[n].first = tree[2*n].first + tree[2*n+1].first;
  tree[n].second = tree[2*n].second + tree[2*n+1].second;
}

void push(int n, int b, int e){
  if(lazy[n]){
    swap(tree[n].first, tree[n].second);
    if(b != e){
      lazy[2*n] ^= 1;
      lazy[2*n+1] ^= 1;
    }
    lazy[n] = 0;
  }
}

void build(int n, int b, int e){
  lazy[n] = 0;
  if(b == e) {
    tree[n] = {a[b] == 0, a[b] == 1};
    return;
  }
  int m = (b + e) / 2;
  build(2*n, b, m);
  build(2*n+1, m+1, e);
  pull(n);
}

void update(int n, int b, int e, int i, int j){
  push(n, b, e);
  if(j < b || e < i) return;
  if(i <= b && e <= j){
    lazy[n] ^= 1;
    push(n, b, e);
    return;
  }
  int m = (b + e) / 2;
  update(2*n, b, m, i, j);
  update(2*n+1, m+1, e, i, j);
  pull(n);
}

pair<int,int> query(int n, int b, int e, int l, int r){
  push(n, b, e);
  if(r < b || e < l) return {0, 0};
  if(l <= b && e <= r) return tree[n];
  int m = (b + e) / 2;
  pair<int,int> left = query(2*n, b, m, l, r);
  pair<int,int> right = query(2*n+1, m+1, e, l, r);
  return {left.first + right.first, left.second + right.second};
}



void solve(){

  int n, m; cin >> n >> m;
  int sum = 0;
  for(int i=1;i<=n;i++) {
    int x, y; cin >> x >> y;
    a[i] = x;
    sum += y;
  }

  build(1, 1, n);
  for(int i=0;i<m;i++){
    char c; cin >> c;
    if(c == 'W'){
      int l, r; cin >> l >> r; l++, r++;
      update(1, 1, n, l, r);
    } else {
      int x; cin >> x;
      pair<int,int> res = query(1, 1, n, 1, n);
      sum += (res.second) * x;
    }
  }
  cout << sum << endl;

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
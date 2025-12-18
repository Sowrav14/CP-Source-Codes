#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
const int N = 2e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;


void solve(){

  int n, m, a, b; cin >> n >> m >> a >> b;
  vector<vector<char>> grid(n, vector<char>(m));
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cin >> grid[i][j];
      }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(grid[i][j] == 'V') continue;
      int x = 0;
      if(i > 0 and grid[i-1][j] == 'V') x = max(x, a);
      if(j > 0 and grid[i][j-1] == 'V') x = max(x, a);
      if(i < n-1 and grid[i+1][j] == 'V') x = max(x, a);
      if(j < m-1 and grid[i][j+1] == 'V') x = max(x, a);
      if(i>0 and j>0 and grid[i-1][j-1] == 'V') x = max(x, b);
      if(i>0 and j<m-1 and grid[i-1][j+1] == 'V') x = max(x, b);
      if(i<n-1 and j>0 and grid[i+1][j-1] == 'V') x = max(x, b);
      if(i<n-1 and j<m-1 and grid[i+1][j+1] == 'V') x = max(x, b);
      grid[i][j] = (char)(x + '0');
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++){
      cout << grid[i][j];
    } cout << endl;
  }
  cout << endl;

}


signed main(){
  Fast_IO()
  int t = 1;
  cin >> t;
  for(int i=1;i<=t;i++){
      cout << "Airplane #" << i << ": \n";
      solve();
  }
}
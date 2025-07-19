#include<bits/stdc++.h>
using namespace std;
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 3005;

int n;
char grid[N][N];
bool visited[N][N];

void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
  string s;cin>>s;
  for(int j=0;j<n;j++) grid[i][j]=s[j];
 }

 queue<pair<int,int>> q;
 q.push({0,0});
 visited[0][0]=1;
 string ans="";
 ans+=grid[0][0];

 while(!q.empty()){
  int sz=q.size();
  char mn='Z'+1;
  vector<pair<int,int>> tmp;

  // First pass to find min char in next layer
  for(int i=0;i<sz;i++){
   auto [x,y]=q.front();q.pop();
   if(x+1<n && !visited[x+1][y]) mn=min(mn,grid[x+1][y]);
   if(y+1<n && !visited[x][y+1]) mn=min(mn,grid[x][y+1]);
   tmp.push_back({x,y});
  }

  // Second pass to push only valid next moves
  for(auto [x,y]:tmp){
   if(x+1<n && !visited[x+1][y] && grid[x+1][y]==mn){
    visited[x+1][y]=1;
    q.push({x+1,y});
   }
   if(y+1<n && !visited[x][y+1] && grid[x][y+1]==mn){
    visited[x][y+1]=1;
    q.push({x,y+1});
   }
  }

  if(!q.empty()) ans+=mn;
 }

 cout<<ans<<'\n';
}

int main(){
 Fast_IO()
 solve();
}

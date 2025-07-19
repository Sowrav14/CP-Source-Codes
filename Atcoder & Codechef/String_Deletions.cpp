#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){
 int n;cin>>n;
 string s;cin>>s;
 string st="";
 for(char c:s){
  st+=c;
  while(st.size()>=3){
   int l=st.size();
   if(st[l-3]!=st[l-2]&&st[l-2]!=st[l-1]){
    char a=st[l-3],b=st[l-1];
    st.pop_back();st.pop_back();st.pop_back();
    st+=a;st+=b;
   }else break;
  }
 }
 cout<<st.size()<<'\n';
}

signed main(){
 Fast_IO()
 int t;cin>>t;
 while(t--)solve();
}

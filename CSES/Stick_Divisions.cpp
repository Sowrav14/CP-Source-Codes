                                                /* God loves You */
 
#include<bits/stdc++.h>
using namespace std;
#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n) for(int i=0;i<int(n);i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=int(n)-1;i>=0;i--)
#define rf1(i,n) for(int i = n;i>=1;i--)
#define saisir(v,x) int x; cin>>x; v.push_back(x);
#define le_debut int main
#define lol long long int
#define endl '\n'
#define pb push_back
#define un first
#define deux second
#define oui cout<<"YES"<<endl
#define non cout<<"NO"<<endl
#define homme cout<<"Bob"<<endl
#define femme cout<<"Alice"<<endl
#define un_de_minus cout<<"-1"<<endl
#define duck cout<<0<<endl;
#define reponse cout<<ans<<endl
#define ici cout<<"Je suis ici"<<endl
const int N = 2*1e5+10;
const int M = 1e9+7;
 
 
// Inline Function
inline lol bigmod(lol x,lol y)  {lol ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
inline lol ad(lol x,lol y)      {lol ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
inline lol sub(lol x,lol y)     {lol ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
inline lol gun(lol x,lol y)     {lol ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
 
 
 
void allons_y(){
 
    lol tot,n; cin >> tot >> n;
    multiset<int>s;
    f(i,n){
    	int x; cin >> x;
    	s.insert(x);
    }
    lol ans = 0;
    while(s.size() != 1){
    	auto a = s.begin();
    	auto b = ++s.begin();
    	lol add = *a + *b;
    	s.erase(a); s.erase(b);
    	s.insert(add);
    	ans += add;
    }
 
    reponse;
    
}
 
 
le_debut(){
    Sowrav_Nath
    int t;
    t = 1;
    // cin >> t;
    while(t--){
        // memset(dp,0,sizeof(dp));
        allons_y();
    }
}
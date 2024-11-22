#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Macros...
#define int                 long long int
#define pii                 pair<int,int>
#define ordered_set         tree<int, null_type, less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Sowrav_Nath         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n)              for(int i=0;i<n;i++)
#define f1(i,n)             for(int i=1;i<=n;i++)
#define rf(i,n)             for(int i=n-1;i>=0;i--)
#define rf1(i,n)            for(int i=n;i>=1;i--)
#define endl                '\n'
#define pb                  push_back
#define oui                 cout << "YES" << endl
#define non                 cout << "NO" << endl
#define homme               cout << "Bob" << endl
#define femme               cout << "Alice" << endl
#define un_de_minus         cout << "-1" << endl
#define duck                cout << 0 << endl;
#define reponse             cout << ans << endl
#define ici                 cout << "Je suis ici" << endl

// Global Variables...
const int N = 2*1e5+10;
const int M = 1e9+7;

// Inline Function...
inline int bigmod(int x,int y, int mod);
inline int inverse_mod(int n,int mod)           {return bigmod(n,mod-2, mod);}
inline int ad(int x,int y, int mod)             {int ret=(x%mod+y%mod)%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}
inline int sub(int x,int y, int mod)            {int ret=((x%mod)-(y%mod)+mod)%mod;    if(ret<0)    {ret+=mod,ret=ret%mod;} return ret;}
inline int gun(int x,int y, int mod)            {int ret=((x%mod)*(y%mod))%mod;   if(ret<0)   {ret+=mod,ret=ret%mod;} return ret;}
inline int bigmod(int x,int y, int mod)         {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%mod;}    y>>=1;x=(x*x)%mod;}   return ret;}
inline int egcd(int a,int b,int &x,int &y)      {if(a==0){ x=0; y=1; return b;} int x1,y1; int d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
inline int inverse(int a, int mod)              { int x, y; int g = egcd(a, mod, x, y); return (g != 1) ? -1 : (x % mod + mod) % mod; }


// Ordered Set Tree
// S.order_of_key (k) : Number of items strictly smaller than k .
// S.find_by_order(k) : K-th element in a set (counting from zero).
struct Point{
    int x,y;
};

bool onSegment(Point p, Point q, Point r) { 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
	return true; 

	return false; 
}

int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
} 


bool doIntersect(Point p1, Point q1, Point p2, Point q2) { 
	int o1 = orientation(p1, q1, p2); 
	int o2 = orientation(p1, q1, q2); 
	int o3 = orientation(p2, q2, p1); 
	int o4 = orientation(p2, q2, q1); 

	if (o1 != o2 && o3 != o4) return true; 

	if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false;
} 

struct network
{
    int id;
    Point p1, p2;
};


void solve(){

    int n, m; cin >> n >> m;
    vector<Point>v;
    f(i,n){
        int x, y; cin >> x >> y;
        Point p;
        p.x = x; p.y = y;
        v.push_back(p);
    }

    vector<network>a, b;
    f1(i,m){
        int x, y, id; cin >> x >> y >> id;
        network net; 
        net.id = i;
        net.p1 = v[x-1];
        net.p2 = v[y-1];
        if(id == 1){
            a.push_back(net);
        } else {
            b.push_back(net);
        }
    }

    // for(auto i : b){
    //     cout << i.id << " " << i.p1.x << " " << i.p1.y << endl;
    // }

    // calculate intercept...
    vector<pair<int,int>>inters;
    for(auto i : a){
        int id = i.id;
        Point p1 = i.p1, p2 = i.p2;
        
        for(auto j : b){
            int iid = j.id;
            Point pp1 = j.p1, pp2 = j.p2;

            if(doIntersect(p1, p2, pp1, pp2)){
                inters.push_back({id, iid});
            }
        }
    }
    int tot = 0;
    vector<int>occ(1010, 0);
    vector<int> adj[1010];
    for(auto i : inters){
        // cout << i.first << " " << i.second << endl;
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
        occ[i.first]++;
        occ[i.second]++;
        tot++;
    }
    // cout << endl;
    set<pair<int,int>>st;
    for(int i=1;i<=1000;i++){
        if(occ[i] == 0) continue;
        st.insert({occ[i], i});
    }
    // for(auto i : st){
    //     // cout << i.first << " " << i.second << endl;
    // }
    vector<int>ans;
    if(tot >= 600000){
        for(int i=1000;i>0;i--){
            int flag = 0;
            for(auto j : adj[i]){
                // cout << j << " ";
                if(j < i) continue;
                flag = 1;
            }
            if(flag) ans.push_back(i);
        }
        cout << ans.size() << endl;
        for(auto i : ans) cout << i << " ";
        cout << endl;
        return;
    }

    
    // cout << st.size() << endl;
    while(!st.empty()){
        auto it = --st.end();
        pair<int,int>x = *it;
        int val = x.second;
        ans.push_back(val);
        st.erase(it);
        for(auto i : adj[val]){
            int x = i;
            int occu = occ[x];
            auto iiit = st.find({occu, x});
            if(iiit == st.end()) continue;
            st.erase(iiit);
            if(occu == 1) continue;
            st.insert({occu-1, x});
            occ[x] = occu - 1;
        }
    }

    // kaz korbe na..
    // for(int i=1;i<=1000;i++){
    //     int flag = 0;
    //     for(auto j : adj[i]){
    //         // cout << j << " ";
    //         if(j < i) continue;
    //         flag = 1;
    //     }
    //     if(flag) ans.push_back(i);
    // }

    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl;

}


signed main(){
    Sowrav_Nath
    int test_cases = 1;
    cin >> test_cases;
    for(int test_case=1;test_case<=test_cases;test_case++){
        cout << "Case #" << test_case << ": " << endl;;
        // memset(dp,0,n*sizeof(int));
        solve();
    }
}
/**
 * @brief   Lis using Binary Search
 *          in this approach dp[i] = length of lis is i and it ends in the minimum number.
 *          so make a lis vector iterate over the given array.
 *          find the upper bound for current element 
 *          if found then replace value in it with current value
 *          if not found then add this to end of lis vector
 *          the size of lis is the required LIS..
 */

/*
    This is in a tree..
    so backtracking is needed...
*/


// #include<bits/stdc++.h>
// using namespace std;

// #define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define f(i,n)              for(int i=0;i<n;i++)
// #define f1(i,n)             for(int i=1;i<=n;i++)
// #define rf(i,n)             for(int i=n-1;i>=0;i--)
// #define rf1(i,n)            for(int i = n;i>=1;i--)
// #define le_debut            signed main
// #define int                 long long int
// #define endl                '\n'
// #define pb                  push_back
// #define oui                 cout << "YES" << endl
// #define non                 cout << "NO" << endl
// #define homme               cout << "Bob" << endl
// #define femme               cout << "Alice" << endl
// #define un_de_minus         cout << "-1" << endl
// #define duck                cout << 0 << endl;
// #define reponse             cout << ans << endl
// #define ici                 cout << "Je suis ici" << endl
// const int N = 1e5+10;
// const int M = 1e9+7;


// // Inline Function
// inline int bigmod(int x,int y)  {int ret=1; while(y>0)  {if(y&1)    {ret=(ret*x)%M;}    y>>=1;x=(x*x)%M;}   return ret;}
// inline int ad(int x,int y)      {int ret=(x%M+y%M)%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}
// inline int sub(int x,int y)     {int ret=((x%M)-(y%M)+M)%M;    if(ret<0)    {ret+=M,ret=ret%M;} return ret;}
// inline int gun(int x,int y)     {int ret=((x%M)*(y%M))%M;   if(ret<0)   {ret+=M,ret=ret%M;} return ret;}

// vector<int>g[N];
// vector<int>v(N);
// vector<int>ans(N);
// vector<int>vis(N);
// vector<int>lis;

// void dfs(int vertex){
//     vis[vertex] = 1;
//     int cur, flag;
//     flag = 0;
//     int it = lower_bound(lis.begin(), lis.end(), v[vertex]) - lis.begin();
//     if(it != lis.size()){
//         cur = lis[it];
//         flag = 1;
//         lis[it] = v[vertex];

//     } else {
//         lis.pb(v[vertex]);
//     }
//     for(auto child : g[vertex]){
//         if(!vis[child]){
//             dfs(child);
//         }
//     }
//     ans[vertex] = lis.size();
//     if(flag){
//         lis[it] = cur;
//     } else{
//         lis.pop_back();
//     }
// }



// void allons_y(){

//     int n; cin >> n;
//     for(int i=2;i<=n;i++){
//         int j; cin >> j;
//         g[i].pb(j);
//         g[j].pb(i);
//     }
//     f1(i,n){
//         int x; cin >> x;
//         v[i] = x;
//     }
//     dfs(1);
//     for(int i=2;i<=n;i++) cout << ans[i] << " "; cout << endl;

// }


// le_debut(){
//     Sowrav_Nath
//     int test = 1;
//     // cin >> test;
//     f1(tc,test){
//         // cout << "Case " << tc << ": ";
//         // memset(dp,0,sizeof(dp));
//         allons_y();
//     }
// }


/**
 * @file C_Challenging_Hike.cpp
 * @author Sowrav Nath
 * @brief   Lis using Segment Tree
 *          First sort the array is ascending using pair to keep trace of formal indices
 *          Iterate(i) over the sorted array with value (val)and traced index(j)
 *          find max(mx) of lis from indices [0, j-1]
 *          update in tree for the index j value = mx
 *          repeat...
 *          Length of lis = tree[1];
 * 
 * @version 0.1
 * @date 2023-09-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
pair<int,int> a[N];
#define f1(i,n) for(int i=1;i<=n;i++)
int n;
int tree[4*N];
vector<int>g[N];
int weight[N];
int ans[N];

void update(int node, int l, int r, int i, int val){
    
    if(i>r or i<l) return;
    if(l == r){
        tree[node] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2*node, l, mid, i, val);
    update(2*node+1, mid+1, r, i, val);
    tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query(int node, int l, int r, int i, int j){
    if(i>r or j<l) return 0;
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    int left = query(2*node, l, mid, i, j);
    int right =query(2*node+1, mid+1, r, i, j);
    return max(left, right);
}


void dfs(int u, int p){
    int x = weight[u];
    // cout << u << " " << x << endl;
    int mx = query(1, 1, n, 0, x-1);
    ans[u] = max(ans[p], mx+1);
    update(1, 1, n, x, mx+1);
    for(auto v : g[u]){
        if(v != p) dfs(v, u);
    }
    update(1, 1, n, x, 0);
}

int main(){
    cin >> n;
    // In tree
    for(int i=2;i<=n;i++){
        int j; cin >> j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    
    map<int,int>mp;
    f1(i,n){
        cin >> weight[i];
        mp[weight[i]]++;
    }
    int it = 1;
    for(auto &i : mp){              // don't need the values
        i.second = it;              // only trace of index is enough
        it++;
    }

    f1(i,n){
        weight[i] = mp[weight[i]];
    }

    dfs(1, 0);
    
    for(int i=2;i<=n;i++) cout << ans[i] << " "; cout << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    // Normal LIS.
    // f1(i,n){
    //     int x; cin >> x;
    //     a[i] = {x, i};
    // }

    // sort(a+1, a+n+1);
    
    // f1(i,n){
    //     int val = a[i].first;
    //     int idx = a[i].second;

    //     int mx = query(1, 1, n, 0, idx-1);
    //     // cout << val << " " << idx << " " << mx << endl;
    //     update(1, 1, n, idx, mx+1);
    // }

    // cout << tree[1] << endl;

}
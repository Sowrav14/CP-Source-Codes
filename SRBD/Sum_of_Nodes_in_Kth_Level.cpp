/**
 * @file Sum_of_Nodes_in_Kth_Level.cpp
 * @author Sowrav Nath (Sowravnath05102002@gmail.com)
 * @version 0.1
 * @date 2025-06-18
 * @copyright Copyright (c) 2025
 * @problem:https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges
 * @tag: Recursion, dfs, parsing
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N = 1e5 + 10;
const int M = 1e9 + 7;
const int inf = 1e12;

int k;
string s;
map<int, vector<int>> g;

int traverse(int &i) {
    if(s[i] == '(') {
        i++;
    if(s[i] == ')') {
        i++;
        return -1;
    }

    string snum = "";
    while(i < s.size() && isdigit(s[i])) {
        snum += s[i++];
    }

    int num = stoi(snum);
    int left = traverse(i);
    if(left != -1) g[num].push_back(left);

    int right = traverse(i);
    if(right != -1) g[num].push_back(right);

    if(i < s.size() && s[i] == ')') i++;
        return num;
    }
    return -1;
}

int ans = 0;
void dfs(int u, int d){
    // cout << u << endl;
    if(d == 0) {
        ans += u;
        return;
    }
    for(auto v : g[u]){
        dfs(v, d-1);
    }
}

void solve(){

    cin >> k;
    cin >> s;

    int i = 0;
    int root = traverse(i);
    // cout << root << endl;

    // for(auto i : g){
    //     cout << i.first << " : ";
    //     for(auto c : i.second) cout << c << " "; cout << endl;
    // }
    dfs(root, k);
    cout << ans << endl;

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
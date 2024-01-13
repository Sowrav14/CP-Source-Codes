#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int a[N];
pair<int,int> tree[4*N];

pair<int,int> merge(pair<int,int> n1, pair<int,int>n2){
    int node1 = n1.first;
    int node2 = n2.first;
    int oc1 = n1.second;
    int oc2 = n2.second;
    if(node1 == node2){
        return {node1, oc1 + oc2};
    } else {
        if(oc1 > oc2){
            return {node1, oc1 - oc2};
        } else {
            return {node2, oc2 - oc1};
        }
    }
}


void build(int node, int l, int r){

    if(l == r){
        tree[node] = {a[l],1};
        return;
    }

    int mid = (l + r) / 2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);
    tree[node] = merge(tree[2*node], tree[2*node + 1]);

}



pair<int,int> query(int node, int l, int r, int i, int j){
    if(i>r or j<l){
        return {0, 0};
    }
    if(i<=l and j>=r){
        return tree[node];
    }

    int mid = (l + r) / 2;
    pair<int,int> left = query(2*node, l, mid, i, j);
    pair<int,int> right = query(2*node+1, mid+1, r, i, j);
    return merge(left, right);
}



int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> freq[n + 10];
        for(int i=0;i<=n;i++){
            freq[i].push_back(-1);
        }
        for(int i=1;i<=n;i++){
            cin >> a[i];
            freq[a[i]].push_back(i);
        }

        build(1, 1, n);
        // cout << tree[1].first << tree[1].second << endl;
        int q; cin >> q;
        for(int i=1;i<=q;i++){
            int x, y; cin >> x >> y;
            pair<int,int> can = query(1, 1, n, x, y);

            // cout << can.second << endl;

            int l = lower_bound(freq[can.first].begin(), freq[can.first].end(), x) - freq[can.first].begin();
            int r = upper_bound(freq[can.first].begin(), freq[can.first].end(), y) - freq[can.first].begin();
            int freq = (r - l);
            int num = y - x + 1;
            if(freq*2 > num){
                cout << freq*2 - num << endl;
            } else {
                cout << 0 << endl;
            }

        }
    }

}
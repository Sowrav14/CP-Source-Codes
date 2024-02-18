#include<bits/stdc++.h>
using namespace std;

const int MAX = 3e5+10; // Max size of array
pair<int,int> tree[4*MAX]; // Segment tree
int lazy[4*MAX]; // Lazy array to propagate updates
int a[MAX];
// Function to build the tree

pair<int,int> getmax(pair<int,int>a, pair<int,int>b){
    if(a.first > b.first){
        return a;
    } else if(a.first < b.first){
        return b;
    } else{
        if(a.second < b.second){
            return a;
        } else{
            return b;
        }
    }
}


void build(int node, int start, int end)
{
	if(start == end)
	{
		// Leaf node will have a single element
		tree[node] = {a[start] + start, start};
	}
	else
	{
		int mid = (start + end) / 2;
		// Recur for the 2 children
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		// Internal node will have the minimum of both of its children
		tree[node] = getmax(tree[2*node], tree[2*node+1]);
	}
}

// Function to update a node
void update(int node, int start, int end, int l, int r, int val)
{
	if(lazy[node] != 0)
	{ 
		// This node needs to be updated
		tree[node].first += lazy[node]; // Update it
		if(start != end)
		{
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
		lazy[node] = 0; // Reset it
	}
	if(start > end or start > r or end < l) return; // Current segment is not within range [l, r]
	if(start >= l and end <= r)
	{
		// Segment is fully within range
		tree[node].first += val;
		if(start != end)
		{
			// Not leaf node
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val); // Updating left child
	update(node*2 + 1, mid + 1, end, l, r, val); // Updating right child
	tree[node] = getmax(tree[node*2], tree[node*2+1]); // Updating root with min value 
}

// Function to query the tree
pair<int,int> query(int node, int start, int end, int l, int r)
{
	if(start > end or start > r or end < l) return {INT_MIN, -1}; // Out of range
	if(lazy[node] != 0)
	{
		// This node needs to be updated
		tree[node].first += lazy[node]; // Update it
		if(start != end)
		{
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}
		lazy[node] = 0; // Reset it
	}
	if(start >= l and end <= r) // Current segment is totally within range [l, r]
		return tree[node];
	int mid = (start + end) / 2;
	pair<int,int> p1 = query(node*2, start, mid, l, r); // Query left child
	pair<int,int> p2 = query(node*2 + 1, mid + 1, end, l, r); // Query right child
	return getmax(p1, p2);
}

void solve()
{
	int n; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    // for(int i=1;i<=2*n;i++) cout << tree[i].first << " " << tree[i].second << endl; 

    // pair<int,int>temp = query(1, 1, n, 1, n);
    // cout << temp.first << " " << temp.second << endl;
    set<int, greater<int>>ans;
    for(int i=1;i<=n;i++){
        pair<int,int>temp = query(1, 1, n, 1, n);
        ans.insert(temp.first);
        update(1, 1, n, temp.second, temp.second, -temp.first);
        update(1, 1, n, temp.second+1, n, -1);
    }

    for(auto i : ans) cout << i << " "; cout << endl;


}


signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}

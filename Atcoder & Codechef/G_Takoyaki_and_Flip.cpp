#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
const int N = 2e5 + 10;
const int inf = 1e18;

struct Node {
    int mx;       // max takoyaki
    int faceUp;   // number of face-up plates
    int addLazy;  // pending add to face-up plates
    Node() : mx(0), faceUp(0), addLazy(0) {}
};

Node seg[4*N];
int n;

// Build segment tree
void build(int id, int l, int r){
    if(l==r){
        seg[id].mx = 0;
        seg[id].faceUp = 1;
        seg[id].addLazy = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    seg[id].mx = max(seg[2*id].mx, seg[2*id+1].mx);
    seg[id].faceUp = seg[2*id].faceUp + seg[2*id+1].faceUp;
    seg[id].addLazy = 0;
}

// Push lazy add to children
void push(int id){
    if(seg[id].addLazy){
        for(int child: {2*id,2*id+1}){
            if(seg[child].faceUp>0){
                seg[child].mx += seg[id].addLazy;
                seg[child].addLazy += seg[id].addLazy;
            }
        }
        seg[id].addLazy = 0;
    }
}

// Type1: add X takoyaki to face-up plates
void updateAdd(int id,int l,int r,int lq,int rq,int val){
    if(r<lq || l>rq || seg[id].faceUp==0) return;
    if(lq<=l && r<=rq){
        seg[id].mx += val;
        seg[id].addLazy += val;
        return;
    }
    push(id);
    int mid = (l+r)/2;
    updateAdd(2*id,l,mid,lq,rq,val);
    updateAdd(2*id+1,mid+1,r,lq,rq,val);
    seg[id].mx = max(seg[2*id].mx, seg[2*id+1].mx);
    seg[id].faceUp = seg[2*id].faceUp + seg[2*id+1].faceUp;
}

// Type2: eat all takoyaki and flip plates if takoyaki>=1
void updateFlip(int id,int l,int r,int lq,int rq){
    if(r<lq || l>rq || seg[id].mx==0) return;
    if(l==r){
        if(seg[id].mx>0){
            seg[id].mx = 0;
            seg[id].faceUp ^= 1;
        }
        seg[id].addLazy = 0;
        return;
    }
    push(id);
    int mid = (l+r)/2;
    updateFlip(2*id,l,mid,lq,rq);
    updateFlip(2*id+1,mid+1,r,lq,rq);
    seg[id].mx = max(seg[2*id].mx, seg[2*id+1].mx);
    seg[id].faceUp = seg[2*id].faceUp + seg[2*id+1].faceUp;
}

// Type3: query max takoyaki in [lq,rq]
int queryMax(int id,int l,int r,int lq,int rq){
    if(r<lq || l>rq) return 0;
    if(lq<=l && r<=rq) return seg[id].mx;
    push(id);
    int mid = (l+r)/2;
    return max(queryMax(2*id,l,mid,lq,rq),
               queryMax(2*id+1,mid+1,r,lq,rq));
}

signed main(){
    Fast_IO()
    int Q;
    cin >> n >> Q;
    build(1,1,n);

    for(int i=0;i<Q;i++){
        int t; cin >> t;
        if(t==1){
            int l,r,x; cin >> l >> r >> x;
            updateAdd(1,1,n,l,r,x);
        }else if(t==2){
            int l,r; cin >> l >> r;
            updateFlip(1,1,n,l,r);
        }else{
            int l,r; cin >> l >> r;
            cout << queryMax(1,1,n,l,r) << endl;
        }
    }
}

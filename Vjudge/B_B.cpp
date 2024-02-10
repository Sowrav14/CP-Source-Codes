#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf = 1e12;


pair<int,int> get(pair<int,int>a , pair<int,int>b){

    if(a.second == 0) return b;
    if(b.second == 0) return a;

    double x = (a.first * 1.0) / (a.second * 1.0);
    double y = (b.first * 1.0) / (b.second * 1.0);

    if(x > y) return a;
    else return b;
}


void solve(){

    int n; cin >> n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    int large[n+1], small[n+1];
    stack<pair<int,int>>st;
    st.push({inf, 0});
    for(int i=1;i<=n;i++){
        int x = v[i];
        while(!st.empty()){
            if(st.top().first > x){
                large[i] = st.top().second;
                break;
            }
            st.pop();
        }
        st.push({x, i});
    }

    stack<pair<int,int>>stt;
    stt.push({inf, n+1});
    for(int i=n;i>=1;i--){
        int x = v[i];
        while(!stt.empty()){
            if(stt.top().first > x){
                small[i] = stt.top().second;
                break;
            }
            stt.pop();
        }
        stt.push({x, i});
    }


    // for(int i=1;i<=n;i++) cout << large[i] << " "; cout << endl;
    // for(int i=1;i<=n;i++) cout << small[i] << " "; cout << endl;

    pair<int,int>ans = {0, 1};
    for(int i=1;i<=n;i++){
        // (i, v[i])
        int x = i;
        int cur = v[i];
        int left = large[i];
        int right = small[i];


        if(left != 0){

            int l = left;
            int hl = v[l];
            int h = v[i];
            int hll = v[l+1];

            int x = i - l;
            int up = hl - h;
            int down = hl - hll;

            up = down * x - up;
            // cout << up << " " << down << endl;

            int g = __gcd(up, down);
            if(g != 0){
                up /= g;
                down /= g;
            }

            pair<int,int> res = {up, down};
            ans = get(res, ans);
        }

        if(right != n+1){
            int r = right;
            int hr = v[r];
            int h = v[i];
            int hrr = v[r-1];

            int x = r - i;
            int up = h - hr;
            int down = hr - hrr;

            up = up + down * x;
            // cout << up << " " << down << endl;

            int g = __gcd(up, down);
            if(g != 0){
                up /= g;
                down /= g;
            }

            pair<int,int> res = {up, down};
            ans = get(ans, res);
        }




        // if(left != 0 and left != i-1){
        //     // cout << i << " left ";
        //     int a = left;
        //     int b = left + 1;

        //     int x = i;
        //     int y = cur;

        //     int x1 = a;
        //     int x2 = v[a];
        //     int y1 = b;
        //     int y2 = v[b];

        //     int up = (y - y2);
        //     int down = (y2 - x2);

        //     up = up + down * a;
        //     // x - (up/down)
        //     up = x * down - up;
        //     int g = __gcd(up, down);
        //     up /= g;
        //     down /= g;
        //     pair<int,int>res = {up, down};
        //     // cout << up << " " << down << endl;
        //     ans = max(ans, res);
        // }

        // if(right != n+1 and right != i+1){
        //     // cout << "right ";
        //     int a = right;
        //     int b = right - 1;

        //     int x = i;
        //     int y = cur;
        //     int x1 = b;
        //     int x2 = v[b];
        //     int y1 = a;
        //     int y2 = v[a];
        //     // (b, v[b]), (a, v[a])
        //     int up = (y - y2);
        //     int down = (y2 - x2);

        //     up = up + down * a;

        //     // (up/down) - x

        //     up = up - x * down;
        //     int g = __gcd(up, down);
        //     up /= g;
        //     down /= g;
        //     pair<int,int> res = {up, down};
        //     ans = get(res, ans);
        //     // cout << up << " " << down << endl;
        // }
    }

    // cout << ans.first << " " << ans.second << endl;
    if(ans.first != 0){
        cout << ans.first << "/" << ans.second << endl;
    } else {
        cout << 0 << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
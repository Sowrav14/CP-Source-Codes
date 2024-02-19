#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(){

    int n; cin >> n;
    vector<int>c,s,d,h;
    char trump; cin >> trump;
    for(int i=0;i<2*n;i++){
        string ss; cin >> ss;
        // cout << ss << endl;
        int x = ss[0] - '0';
        char y = ss[1];
        // cout << x << " " << y << endl;
        if(y == 'C'){
            c.push_back(x);
        } else if(y == 'S'){
            s.push_back(x);
        } else if(y == 'D'){
            d.push_back(x);
        } else if(y == 'H'){
            h.push_back(x);
        }
    }

    vector<pair<string, string>>ans;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    sort(h.begin(), h.end());
    sort(s.begin(), s.end());
    vector<string>trumper;

    if('C' != trump){
        int sz = c.size();
        if(c.size()%2){
            string temp = "C";
            char tt = c.back() + '0';
            temp += tt;
            trumper.push_back(temp);
            sz--;
        }
        for(int i=0;i<sz;i+=2){
            string one = "C";
            one += (c[i] + '0');
            string two = "C";
            two += (c[i+1] + '0');
            // cout << one << " " << two << endl;
            ans.push_back({one, two});
        }
    }

    

    if(trump != 'S'){
        int sz = s.size();
        if(s.size()%2){
            string temp = "S";
            char tt = s.back() + '0';
            temp += tt;
            trumper.push_back(temp);
            sz--;
        }
        for(int i=0;i<sz;i+=2){
            string one = "S";
            one += (s[i] + '0');
            string two = "S";
            two += (s[i+1] + '0');
            // cout << one << " " << two << endl;
            ans.push_back({one, two});
        }
    }

    // for(auto i : ans ){
    //     cout << i.first << " " << i.second << endl;
    // }


    if(trump != 'H'){
        int sz = h.size();
        if(h.size()%2){
            string temp = "H";
            char tt = h.back() + '0';
            temp += tt;
            trumper.push_back(temp);
            sz--;
        }
        for(int i=0;i<sz;i+=2){
            string one = "H";
            one += (h[i] + '0');
            string two = "H";
            two += (h[i+1] + '0');
            // cout << one << " " << two << endl;
            ans.push_back({one, two});
        }
    }

    if(trump != 'D'){
        int sz = d.size();
        if(d.size()%2){
            string temp = "D";
            char tt = d.back() + '0';
            temp += tt;
            trumper.push_back(temp);
            sz--;
        }
        for(int i=0;i<sz;i+=2){
            string one = "D";
            one += (d[i] + '0');
            string two = "D";
            two += (d[i+1] + '0');
            // cout << one << " " << two << endl;
            ans.push_back({one, two});
        }
    }

    vector<string>triump;

    if(trump == 'C'){
        for(int i=0;i<c.size();i++){
            string temp = "C";
            char tt = c[i] + '0';
            temp += tt;
            triump.push_back(temp);
        }
    }

    if(trump == 'D'){
        for(int i=0;i<d.size();i++){
            string temp = "D";
            char tt = d[i] + '0';
            temp += tt;
            triump.push_back(temp);
        }
    }

    if(trump == 'S'){
        for(int i=0;i<s.size();i++){
            string temp = "S";
            char tt = s[i] + '0';
            temp += tt;
            triump.push_back(temp);
        }
    }

    if(trump == 'H'){
        for(int i=0;i<h.size();i++){
            string temp = "H";
            char tt = h[i] + '0';
            temp += tt;
            triump.push_back(temp);
        }
    }

    // cout << trumper.size() <<  " " << triump.size() << endl;

    if(trumper.size() > triump.size()){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int j = 0;
    for(int i=0;i<trumper.size();i++){
        ans.push_back({trumper[i], triump[j]});
        j++;
    }

    int left = triump.size() - j;
    if(left%2){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(;j<triump.size();j+=2){
        ans.push_back({triump[j], triump[j+1]});
    }

    for(auto &i : ans ){
        reverse(i.first.begin(), i.first.end());
        reverse(i.second.begin(), i.second.end());
        cout << i.first << " " << i.second << endl;
    }

}


signed main(){
    Fast_IO()
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
        // cout << "Case " << t << ": ";
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fast_IO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void convertTime(int hours, int minutes) {
    // Calculate hours in 12-hour format
    int hours12 = (hours % 12 == 0) ? 12 : hours % 12;

    // Determine if it's AM or PM
    string period = (hours < 12) ? "AM" : "PM";

    // Print the converted time
    if(hours12 < 10) cout << "0";
    cout << hours12 << ":";

    // Add leading zero if minutes are less than 10
    if (minutes < 10)
        cout << "0";

    cout << minutes << " " << period << endl;
}


void solve(){

    string s; cin >> s;

    string hr = ""; hr += s[0]; hr += s[1];
    int hrr = stol(hr);
    
    string mn = ""; mn += s[3]; mn += s[4];
    int mnn = stol(mn);

    // cout << hrr << " " << mnn << endl;

    convertTime(hrr, mnn);

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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Fast_IO()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"

struct Punch
{
    bool in; // '>' = in
    int h, m;
};

int toMin(int h, int m) { return h * 60 + m; }
int overlap(int a, int b, int c, int d) { return max(0LL, min(b, d) - max(a, c)); }

int32_t main()
{
    Fast_IO() int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << "Absent\n";
            continue;
        }
        vector<Punch> v(n);
        for (int i = 0; i < n; i++)
        {
            string s, t;
            cin >> s >> t;
            v[i].in = (s[0] == '>');
            v[i].h = stoi(t.substr(0, 2));
            v[i].m = stoi(t.substr(3, 2));
        }

        // Fix special: last punch-out at 00:00 -> 24:00
        if (!v.back().in && v.back().h == 0 && v.back().m == 0)
        {
            v.back().h = 24;
            v.back().m = 0;
        }

        // Constants
        const int START = 7 * 60; // working hour count starts from 07:00
        const int LATE1 = 10 * 60 + 30;
        const int LUNCH1 = 13 * 60;
        const int LUNCH2 = 14 * 60;
        const int LATE2 = 14 * 60 + 30;
        const int ABSENT_THR = 15 * 60;
        const int OVERTIME_MIN = 12 * 60;
        const int FULLDAY_MIN = 8 * 60;
        const int HALF_MIN = 4 * 60;
        const int FIRST_HALF_LOSS_THRESHOLD = 11 * 60; // after 11:00 loses 1st half / Full / OT

        // find first punch-in
        int firstIn = -1;
        for (auto &x : v)
            if (x.in)
            {
                firstIn = toMin(x.h, x.m);
                break;
            }
        if (firstIn == -1 || firstIn > ABSENT_THR)
        {
            cout << "Absent\n";
            continue;
        }

        // Determine effective counting start
        int effectiveStart = max(firstIn, START);
        bool canBeFullOrFirstHalf = true;
        if (firstIn > FIRST_HALF_LOSS_THRESHOLD)
        {
            effectiveStart = max(firstIn, LUNCH2); // count starts from 14:00
            canBeFullOrFirstHalf = false;          // Full day / Overtime / 1st Half not possible
        }

        // calculate total working minutes
        int total = 0;
        for (int i = 0; i + 1 < n; i += 2)
        {
            int in = toMin(v[i].h, v[i].m);
            int out = toMin(v[i + 1].h, v[i + 1].m);
            int segL = max(in, effectiveStart);
            int segR = out;
            if (segR <= segL)
                continue;
            int dur = segR - segL - overlap(segL, segR, LUNCH1, LUNCH2);
            if (dur > 0)
                total += dur;
        }

        // cout << total << endl;
        string ans = "Absent";
        bool late = false;

        if (canBeFullOrFirstHalf)
        {
            if (total >= OVERTIME_MIN)
                ans = "Overtime";
            else if (total >= FULLDAY_MIN)
                ans = "Full Day";
            else if (total >= HALF_MIN)
                ans = "1st Half";
            else
                ans = "Absent";
        }
        else
        { // only 2nd Half possible
            if (total >= HALF_MIN)
                ans = "2nd Half";
            else
                ans = "Absent";
        }

        // check late
        if (ans != "Absent")
        {
            if (ans == "2nd Half")
            {
                if (firstIn > LATE2)
                    late = true; // first-in after 14:00 -> late
            }
            else
            {
                if (firstIn > LATE1)
                    late = true; // for Full/1st/OT: first-in after 07:00 -> late
            }
        }

        cout << ans;
        if (ans != "Absent" && late)
            cout << " ~";
        cout << endl;
    }
}

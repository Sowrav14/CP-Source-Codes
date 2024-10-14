#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void funofdiv()
{
	ll n, m, x, y, z, i, j, k, l = 0, sum = 0, ans = 0;
	cin >> n;
	vector<ll> a(1, 0);
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		a.pb(x);
	}
	sort(a.begin() + 1, a.end());
	j = 1;
	for (i = 1; i <= n; i++)
	{
		while (j <= n && (a[j] - a[i]) <= 10)
		{
			j++;
		}
		ans = max(ans, j - i);
	}
	cout << ans << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n = 1;
	// cin >> n;
	while (n--)
	{
		funofdiv();
	}
	return 0;
}
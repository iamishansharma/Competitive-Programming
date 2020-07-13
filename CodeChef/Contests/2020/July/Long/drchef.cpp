#include <bits/stdc++.h>
using namespace std;
#define fastIO          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)        {   cout << #x << " = " << x <<endl;    }
#define ll              long long int

void solve()
{
	ll n;
	ll x;
	ll days = 0;
	cin >> n >> x;

	vector<ll> a(n);

	for(int i=0; i<n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll start = 0;

	for(; start<a.size(); start++)
		if(a[start] >= x)
			break;

	for(int i=start; i<n; i++)
	{
		if(x < a[i])
		{
			while(x < a[i])
			{
				x *= 2;
				days++;
			}
		}
		days++;
		x = a[i] * 2;
	}
	
	if(start == 0)
		cout << start + days << endl;
	else
	{
		ll total = start + days;

		days = 0;
		start--;

		for(int i=start; i<n; i++)
		{
			if(x < a[i])
			{
				while(x < a[i])
				{
					x *= 2;
					days++;
				}
			}
			days++;
			x = a[i] * 2;
		}
		cout << min(days+start, total) << endl;
	}
}

int main()
{
	fastIO;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}
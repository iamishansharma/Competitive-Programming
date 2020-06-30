#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	ll k=0;
	cin>>n>>k;

	vector<int> v(n);

	ll rev = 0;
	
	for(int i=0; i<v.size(); i++)
	{
		cin>>v[i];
		rev += v[i];
	}

	ll revreal = 0;

	for(int i=0; i<v.size(); i++)
	{
		if(v[i] > k)
			v[i] = k;

		revreal += v[i];
	}

	cout<<rev-revreal<<endl;
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
#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n;
	int q;

	cin>>n>>q;

	vector<pair<int,int>> pt(n);

	for(int i=0; i<n; i++)
	{
		int p1, p2;
		cin>>p1>>p2;

		pt[i] = make_pair(p1,p2);
	}

	for(int i=0; i<q; i++)
	{
		int q1,q2;
		cin>>q1>>q2;		
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
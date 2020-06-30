#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	int m=0;
	cin>>m;

	vector<int> a(n);
	
	for(int i=0; i<a.size(); i++)
		cin>>a[i];
	
	vector<int> b(n);
	
	for(int i=0; i<b.size(); i++)
		cin>>b[i];
	
	vector<vector<int>> net(n, vector<int> n);

	int temp1, temp2;

	for(int i=0; i<m; i++)
	{
		cin>>temp1>>temp2;

		net[temp1-1][temp2-1] = 1;
		net[temp2-1][temp1-1] = 1;
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
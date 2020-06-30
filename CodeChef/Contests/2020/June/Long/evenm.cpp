#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll n=0;
	cin>>n;

	vector<vector<int>> result(n, vector<int> (n));

	int xBeg=0,xEnd=n-1;
	int yBeg=0,yEnd=n-1;
	int cur=1;

	while(true)
	{
		for(int i=yBeg;i<=yEnd;i++) 
			result[xBeg][i]=cur++;

		if(++xBeg>xEnd) 
			break;

		for(int i=xBeg;i<=xEnd;i++) 
			result[i][yEnd]=cur++;

		if(--yEnd<yBeg) 
			break;

		for(int i=yEnd;i>=yBeg;i--) 
			result[xEnd][i]=cur++;

		if(--xEnd<xBeg) 
			break;

		for(int i=xEnd;i>=xBeg;i--) 
			result[i][yBeg]=cur++;
		
		if(++yBeg>yEnd) 
			break;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
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
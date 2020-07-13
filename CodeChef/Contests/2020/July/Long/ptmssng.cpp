#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	map<int,int> x;
	map<int,int> y;

	int ansx = 0;
	int ansy = 0;

	for(int i=0; i < 4*n-1; i++)
	{
		int n1;
		int n2;

		cin>>n1>>n2;

		x[n1]++;
		y[n2]++;
	}

	auto i = x.begin();
	auto j = y.begin();

	for(; i != x.end() && j != y.end(); i++, j++)
	{
		if(i->second % 2 != 0)
			ansx = i->first;

		if(j->second % 2 != 0)
			ansy = j->first;
	}

	cout<<ansx<<" "<<ansy<<endl;
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
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

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];

	sort(v.begin(), v.end());

	unordered_map<int,int> mp;

	for(int i=0; i<v.size(); i++) 
		mp[v[i]] = 1;

	int index = -1;

	for(int i = 1; i <= n + 1; i++) 
	{
		if(mp[i] == 0) 
		{
			index = i;
			break;
		}
	}

	if(index == m)
		cout<<v.size()<<endl;
	else
	{
		int count = 0;
		int before = 0;

		for(int i=0; i<v.size(); i++)
		{
			if(v[i] < m)
				before++;

			if(v[i] == m)
				count++;
		}

		if(before == 0)
			cout<<"-1"<<endl;
		else
			cout<<v.size()-count<<endl;
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
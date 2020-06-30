#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	int b=0;
	cin>>b;

	int m=0;
	cin>>m;

	vector<int> v(m);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	unordered_map<int,int> mp;

	int entry = 0;

	int block = 1;

	for(int i=0; i<n; i++)
	{
		mp[i] = block;

		entry++;

		if(entry == b)
		{
			entry = 0;
			block++;
		}
	}

	if(v.size() == 0)
		cout<<"0"<<endl;
	else
	{
		int init = mp[v[0]];

		int count = 1;

		for(int i=0; i<v.size(); i++)
		{
			if(init == mp[v[i]])
			{
				continue;
			}
			else
			{
				count++;
				init = mp[v[i]];
			}
		}

		cout<<count<<endl;
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
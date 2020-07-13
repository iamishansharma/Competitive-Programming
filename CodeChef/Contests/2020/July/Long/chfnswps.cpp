#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

bool comp(int a, int b)
{
	return a > b;
}

void solve()
{
	int n=0;
	cin>>n;

	vector<int> a(n);

	for(int i=0; i<n; i++)
		cin>>a[i];

	vector<int> b(n);

	for(int i=0; i<n; i++)
		cin>>b[i];

	map<int,int> am;
	map<int,int> bm;
	map<int,int> abm;

	for(int i=0; i<n; i++)
	{
		am[a[i]]++;
		bm[b[i]]++;
		abm[a[i]]++;
		abm[b[i]]++;
	}

	bool odd = false;

	for(auto i:abm)
	{
		if(i.second % 2 != 0)
		{
			odd = true;
			break;
		}
	}

	if(odd)
		cout<<"-1"<<endl;
	else
	{
		if(am == bm)
		{
			cout<<"0"<<endl;
		}
		else
		{
			vector<int> v1;
			vector<int> v2;

			int minval = INT_MAX;

			for(int i=0; i<n; i++)
				minval = min(minval, min(a[i],b[i]));

			map<int,int> m1;
			map<int,int> m2;

			for(auto i:am)
				if(i.second > bm[i.first])
					m1[i.first] = (i.second - bm[i.first])/2;

			for(auto i:bm)
				if(i.second > am[i.first])
					m2[i.first] = (i.second - am[i.first])/2;

			for(auto i:m1)
				for(int j=0; j<i.second; j++)
					v1.push_back(i.first);

			for(auto i:m2)
				for(int j=0; j<i.second; j++)
					v2.push_back(i.first);

			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end(), comp);

			ll ans = 0;

			for(int i=0; i<v1.size(); i++)
				ans += min(minval * 2, min(v1[i],v2[i]));

			cout<<ans<<endl;
		}
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
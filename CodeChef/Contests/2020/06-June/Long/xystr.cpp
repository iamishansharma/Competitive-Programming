#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	string str;
	cin>>str;

	vector<pair<int,int>> xyyx;

	for(int i=0; i<str.length()-1; i++)
	{
		if(str[i] == 'x' && str[i+1] == 'y')
			xyyx.push_back(make_pair(i,i+1));
		else if(str[i] == 'y' && str[i+1] == 'x')
			xyyx.push_back(make_pair(i,i+1));
	}

	if(xyyx.size() == 0)
		cout<<"0"<<endl;
	else
	{
		map<int,int> m;
		m.clear();

		int count = 0;

		for(int i=0; i<xyyx.size(); i++)
		{
			if(m[xyyx[i].first] == 0 && m[xyyx[i].second] == 0)
			{
				m[xyyx[i].first] = 1;
				m[xyyx[i].second] = 1;
				count++;
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
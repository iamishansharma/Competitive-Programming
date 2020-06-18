#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	int evenbutodd = 0;
	int oddbuteven = 0;

	for(int i=0; i<n; i++)
	{
		if((i % 2) != (v[i] % 2))
		{
			if(i % 2 == 0)
				evenbutodd++;
			else
				oddbuteven++;
		}
	}

	if(evenbutodd == 0 && oddbuteven == 0)
		cout<<"0"<<endl;
	else
	{
		if(evenbutodd != oddbuteven)
			cout<<"-1"<<endl;
		else
			cout<<oddbuteven<<endl;
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
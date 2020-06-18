#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{

	/* Partially Correct Only */

	int n=0;
	cin>>n;

	vector<int> v(n);
	
	for(int i=0; i<v.size(); i++)
		cin>>v[i];
	
	int change5 = 0;
	int change10 = 0;
	int change15 = 0;

	int flag = 0;

	for(int i=0; i<n; i++)
	{
		if(v[i] == 5)
			change5++;
		else if(v[i] == 10)
		{
			if(change5 >= 1)
			{
				change5--;
				change10++;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		else if(v[i] == 15)
		{
			if(change10 >= 1)
			{
				change10--;
				change15++;
			}
			else if(change5 >= 2)
			{
				change5 = change5 - 2;
				change15++;
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}

	if(flag)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
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
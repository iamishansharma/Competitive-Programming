#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int s=0;
	cin>>s;

	int n=0;
	cin>>n;

	if(s == 1)
		cout<<"1"<<endl;
	else
	{
		if(s < n)
		{
			if(s % 2 == 0)
				cout<<"1"<<endl;
			else
				cout<<"2"<<endl;
		}
		else if(s == n)
			cout<<"1"<<endl;
		else
		{
			int maxval = s/n;
			int left = s % n;

			if(left == 0)
				cout<<maxval<<endl;
			else
			{
				if(left == 1 || left % 2 == 0)
					cout<<maxval + 1<<endl;
				else if(left % 2 != 0)
				{
					cout<<maxval + 2<<endl;
				}
			}
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
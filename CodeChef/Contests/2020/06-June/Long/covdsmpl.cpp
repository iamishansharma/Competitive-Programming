#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n = 0;
	cin>>n;

	int p = 0;
	cin>>p;

	vector<vector<int> > mat(n+1, vector<int> (n+1));

	// REMEMBER USING 1 INDEX HERE

	/*

		Status: Correct Answer by Brute Force.

		Optimise this
	
	 */

	int choice = 1;
	int x = 0;

	int total = 0;

	cout<<choice<<" "<<"1"<<" "<<n<<" "<<"1"<<" "<<n<<endl;
	cin>>total;

	/*

	BRUTE FORCE

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			//fflush(stdout);
			cout<<choice<<" "<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
			cin>>x;

			if(x == -1)
				exit(0);
			else
				if(x == 1)
					mat[i][j] = 1;
		}
	}

	*/

	choice = 2;
	cout<<choice<<endl;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}

	cin>>x;

	if(x == -1)
		exit(0);
}

int main()
{
	fastIO;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); 
		freopen("output.txt", "w", stdout); 
	#endif*/
	
	int tc=0;
	cin>>tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int k=0;
	cin>>k;

	vector<vector<char>> board(8, vector<char> (8));

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			board[i][j] = '.';

	/*Do here*/

	board[0][0] = 'O';

	int obs = 64-k;

	for(int i=7; i>=0; i--)
	{
		for(int j=7; j>=0; j--)
		{
			if(obs != 0)
			{
				board[i][j] = 'X';
				obs--;
			}
		}
	}

	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
			cout<<board[i][j];
		cout<<endl;
	}
	//cout<<endl;
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
#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	vector<ll> arr1(3);
	vector<ll> arr2(3);

	cin>>arr1[0]>>arr1[1]>>arr1[2];
	cin>>arr2[0]>>arr2[1]>>arr2[2];

	ll steps = 0;

	/*
		Notes:

		1. We know currently that max steps can be 3; i.e. 
		just difference from its corresponding elements.

		2. So by that logic, if 1 element is already same, max steps = 2;

		3. if 2 elements are same, max steps = 1;

		2 4 6
		9 15 21
	*/

	cout<<steps<<endl;
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
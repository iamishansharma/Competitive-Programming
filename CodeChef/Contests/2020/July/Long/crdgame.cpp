#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

ll getSum(ll n)
{
	ll sum = 0;

	while(n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void solve()
{
	int n=0;
	cin>>n;

	ll chef = 0;
	ll morty = 0;

	for(int i=0; i<n; i++)
	{
		ll p1 = 0;
		ll p2 = 0;

		cin>>p1>>p2;

		ll sum1 = getSum(p1);
		ll sum2 = getSum(p2);

		if(sum1 > sum2)
			chef++;
		else if(sum2 > sum1)
			morty++;
		else
		{
			chef++;
			morty++;
		}
	}

	if(chef > morty)
		cout<<"0 "<<chef<<endl;
	else if(chef == morty)
		cout<<"2 "<<chef<<endl;
	else
		cout<<"1 "<<morty<<endl;
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
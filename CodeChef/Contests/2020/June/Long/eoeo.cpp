#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cerr << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	ll ts = 0;
	cin>>ts;

	if(ts == 1)
	{
		//cout<<"TS: "<<ts<<" : 0"<<endl;
		cout<<"0"<<endl;
	}
	else
	{
		if(ts % 2 != 0)
		{
			//cout<<"TS: "<<ts<<" : "<<ts/2<<endl;
			cout<<ts/2<<endl;
		}
		else
		{
			if(log2(ts) - floor(log2(ts)) == 0)
			{
				//cout<<"TS: "<<ts<<" : 0"<<endl;
				cout<<"0"<<endl;
			}
			else
			{
				ll temp = ts;

				int count = 0;

				while(temp % 2 == 0)
				{
					temp = temp / 2;
					count++;

					if(temp % 2 != 0)
						break;
				}
				int num = pow(2,count+1);
				//cout<<"TS: "<<ts<<" : "<<ts/num<<endl;
				cout<<ts/num<<endl;
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
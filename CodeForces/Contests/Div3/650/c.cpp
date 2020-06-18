#include <bits/stdc++.h>
using namespace std;
#define fastIO 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define debug(x)		{	cout << #x << " = " << x <<endl;	}
#define ll	 			long long int

void solve()
{
	int n=0;
	cin>>n;

	int k=0;
	cin>>k;

	string str;
	cin>>str;

	vector<int> v(n);

	for(int i=0; i<n; i++)
		v[i] = i;

	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == '1')
		{
			for(int j = i-k; j <= i+k; j++)
			{
				if(j >= 0 && j <= str.size()-1)
					v[j] = -1;
			}
		}
	}

	//for(int i=0; i<v.size(); i++)
		//cout<<v[i]<<" ";

	//cout<<endl;

	int count1 = 0;

	for(int i=0; i<v.size(); i++)
		if(v[i] == -1)
			count1++;

	if(count1 == 0)
	{
		int ans = 0;

		for(int i=0; i<str.size(); i=i+k+1)
			ans++;

		cout<<ans<<endl;
	}
	else
	{
		int not1 = 0;

		for(int i=0; i<v.size(); i++)
			if(v[i] != -1)
				not1++;

		cout<<not1<<endl;
	}

	/*int count1 = 0;

	for(int i=0; i<str.size(); i++)
		if(str[i] == '1')
			count1++;

	if(count1 == 0)
	{
		int ans = 0;

		for(int i=0; i<str.size(); i=i+k+1)
			ans++;

		cout<<ans<<endl;
	}
	else
	{
		set<int> ans;

		for(int i=0; i<str.size(); i++)
		{
			if(str[i] == '1')
			{
				if(i-k-1 >= 0)
				{
					if(str[i-k-1] == '0')
						ans.insert(i-k-1);
				}

				if(i+k+1 <= str.size()-1)
				{
					if(str[i+k+1] == '0')
						ans.insert(i+k+1);
				}
			}
		}

		if(ans.empty())
			cout<<"0"<<endl;
		else
		{
			for(auto itr:ans)
				cout<<itr<<" ";

			cout<<endl;
		}
	}*/
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
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int,vi,greater<int> >
#define mod             1000000007
#define inf             1e18
#define f(i,n)          for(int i=0;i<n;i++)
#define w(x)            int x; cin>>x; while(x--)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define mk(arr,n,type)  type *arr=new type[n];
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
 
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
 
	int n;
	cin >> n;
	int a[n];
	f(i, n)
	{
		cin >> a[i];
	}
	int pre[n] = {};
	bool x = true;
	pre[0] = a[0];
	if (pre[0] < 0)
		x = false;
	for (int i = 1; i < n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
 
	}
	int cnt = 0;
	vector<int> v;
	f(i, n)
	{
		if (pre[i] < 0)
			x = false;
		//cout << pre[i] << " ";
 
		if (pre[i] == 0)
		{
			v.pb(i);
			cnt++;
		}
	}
	//cout << endl;
	if (pre[n - 1] != 0)
		x = false;
	f(i, v.size())
	{
		int z = v[i];
 
		if (i == 0)
		{	mii mq;
			for (int j = 0; j <= v[i]; j++)
			{
				if (mq.find(a[j]) == mq.end())
				{
					mq[a[j]]++;
				}
				else
				{
					x = false;
					break;
				}
			}
			//cout << x << endl;
		}
		// else if (i == v.size() - 1)
		// {
		// 	if (v[i] != n - 1)
		// 	{
		// 		x = false;
		// 	}
		// 	//cout << x << endl;
		// }
		else
		{	mii mq;
			int y = v[i];
			for (int j = v[i - 1] + 1; j <= y; j++)
			{
				if (mq.find(a[j]) == mq.end())
				{
					mq[a[j]]++;
				}
				else
				{
					x = false;
					break;
				}
			}
			//cout << x << endl;
		}
		if (x == false)
			break;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
		{
			mii mq;
			for (int j = 0; j <= v[i]; j++)
			{
				if (a[j] > 0)
					mq[a[j]]++;
				else
				{
					int x = abs(a[j]);
					mq[x]--;
				}
 
			}
			//cout << v[i] << endl << mq.size() << endl;
			for (auto q = mq.begin(); q != mq.end(); q++)
			{
				//cout << q->first << " " << q->second << endl;
 
				if (q->second != 0)
				{
					x = false;
					break;
				}
			}
			//cout << x << endl;
		}
		else
		{
			mii mq;
			for (int j = v[i - 1] + 1; j <= v[i]; j++)
			{
				if (a[j] > 0)
					mq[a[j]]++;
				else
				{
					int x = abs(a[j]);
					mq[x]--;
				}
 
			}
			for (auto q = mq.begin(); q != mq.end(); q++)
			{
				if (q->second != 0)
				{
					x = false;
					break;
				}
			}
		}
		if (x == false)
			break;
	}
	if (!x || cnt == 0)
		cout << -1 << endl;
	else
	{
		cout << cnt << endl;
		f(i, v.size())
		{
			if (i == 0)
				cout << v[i] + 1 << " ";
			else
				cout << v[i] - v[i - 1] << " ";
		}
		cout << endl;
	}
}

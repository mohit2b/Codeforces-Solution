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
 
	w(q)
	{
		int n;
		cin >> n;
		mii mq;
		f(i, n)
		{
			int x;
			cin >> x;
			mq[x]++;
 
		}
		set<int> st;
		vector<int> v;
		for (auto z = mq.begin(); z != mq.end(); z++)
		{
 
 
			v.pb(z->second);
 
 
 
		}
		sort(v.begin(), v.end());
		vector<int> y;
 
		for (int i = v.size() - 1; i >= 0; i--)
		{
 
 
			if (y.size() == 0)
			{
				y.pb(v[i]);
				st.insert(v[i]);
			}
			else
			{
				int aa = y.size() - 1;
				if (st.find(v[i]) != st.end())
				{
					if (y[aa] >= 1)
					{	y.pb(y[aa] - 1);
						st.insert(y[aa] - 1);
					}
 
				}
				else
				{
					y.pb(v[i]);
					st.insert(v[i]);
				}
			}
 
		}
 
 
		int sum = 0;
 
		for (int i = 0; i < y.size(); i++)
		{
			//cout << y[i] << " ";
			int e = y[i];
			sum += e;
		}
		//cout << endl;
		cout << sum << endl;
	}
 
}
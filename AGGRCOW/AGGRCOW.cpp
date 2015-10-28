#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define imax INT_MAX
#define imin INT_MIN
#define sd(x) scanf("%lld", &x)
#define p(x) printf("%lld\n",x)

ll n,c,i;
ll stalls[100001];
ll F(ll x)
{
	ll cmpltd=1, last=stalls[0];
	for(i=1;i<n;i++)
	{
		if(stalls[i]-last>=x)
		{
			if(++cmpltd==c) return 1; 
			last=stalls[i];
		}
	}
	return 0;
}
int main()
{
	ll t;
	sd(t);
	while(t--)
	{
		
		sd(n);
		sd(c);
		for(i=0;i<n;i++)
		{
			cin>>stalls[i];
		}
		sort(stalls, stalls+n);
		ll start=0;
		ll end=stalls[n-1]-stalls[0]+1;
		ll mid;
		while(end-start>1)
		{
			mid=(end+start)>>1;
			if(F(mid))
			{
				start=mid;
			}
			else
			{
				end=mid;
			}
		}
		p(start);
	}
	return 0;
}

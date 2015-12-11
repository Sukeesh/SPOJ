#include "bits/stdc++.h"
using namespace std;

#define ll long long int
ll BIT[10000100],n,a[200200],cnt=0,max_till_now=INT_MIN;

inline void make_fenwick(ll idx){
	while(idx<=max_till_now){
		BIT[idx]+=1;
		idx+=idx&(-idx);
	}
}

ll query_fenwick(ll idx){
	ll res=0;
	while(idx>0){
		res+=BIT[idx];
		idx-=idx&(-idx);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t,i;
	cin >> t;
	while(t--){
		cnt=0;
		memset(a,0,sizeof(a));
		memset(BIT,0,sizeof(BIT));
		cin >> n;
		max_till_now=INT_MIN;
		for(i=1;i<=n;i++){
			cin >> a[i];
			max_till_now=max(max_till_now,a[i]);
		}
		for(i=1;i<=n;i++){
			make_fenwick(a[i]);
			cnt+=query_fenwick(max_till_now)-query_fenwick(a[i]);
		}
		cout << cnt << endl;
	}
	return 0;
}

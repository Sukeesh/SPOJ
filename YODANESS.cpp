#include "bits/stdc++.h"
using namespace std;

#define ll long long int
map<string, ll> indx;
ll n,BIT[30030],cnt=0;

inline void make_fenwick(ll idx){
	while(idx<=n){
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
	ll t; cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		memset(BIT,0,sizeof(BIT));
		indx.clear();
		string str[n+1];
		ll i; 
		for(i=1;i<=n;++i){
			cin>>str[i];
			indx[str[i]]=i;
		}
		string astr[n+1];
		for(i=1;i<=n;i++){
			cin>>astr[i];
			make_fenwick(indx[astr[i]]);
			cnt+=query_fenwick(n)-query_fenwick(indx[astr[i]]);
		}
		cout<<cnt<<endl;
	}
	return 0;
}

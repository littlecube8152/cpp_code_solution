
#include <bits/stdc++.h>
#define int long long 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define x first
#define y second
using namespace std;
int n,d,m,ans=0;
map<pii,int>rod,one;
map<pii,int>id;
set<int>st[300015][2];
int Erase(int i,int cost,bool go){
	int tans=0;
	while (!st[i][0].empty()&&!st[i][1].empty()){
		if (go){
			auto down=st[i][0].begin();
			auto up=st[i][1].upper_bound(*down);
			if (up==st[i][1].end())
				break;
			st[i][0].erase(down);
			st[i][1].erase(up);
			tans+=cost;
		}
		else {
			auto down=prev(st[i][0].end());
			auto up=st[i][1].lower_bound(*down);
			if (up==st[i][1].begin())
				break;
			up=prev(up);
			st[i][0].erase(down);
			st[i][1].erase(up);
			tans+=cost;
		}
	}
	return tans;
}	
void solve(pii edge){
	int i=id[edge];
	if (st[i][0].empty()&&st[i][1].empty())
		return;
	if (rod[edge]>rod[pii(edge.y,edge.x)]){
		ans=ans+Erase(i,rod[pii(edge.y,edge.x)],0);
		ans=ans+Erase(i,rod[edge],1);
	}
	else {
		ans=ans+Erase(i,rod[edge],1);
		ans=ans+Erase(i,rod[pii(edge.y,edge.x)],0);
	}
	ans=ans+one[edge]*st[i][0].size();
	ans=ans+one[pii(edge.y,edge.x)]*st[i][1].size();
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>d;
	int l,num=0; cin>>l;
	for (int i=2;i<=d;i++){
		int now,idx,bk; cin>>now;
		if (!id[pii(l,now)]&&!id[pii(now,l)])
			id[pii(l,now)]=++num;
		if (id[pii(l,now)])
			idx=id[pii(l,now)],bk=0;
		else idx=id[pii(now,l)],bk=1;
		st[idx][bk].insert(i);
		l=now;
	}
	cin>>m;
	for (int i=1;i<=m;i++){
		int a,b,p,mn,mx;
		char c; cin>>a>>b>>c>>p;
		if (c=='R'){
			if (!rod[pii(a,b)]||rod[pii(a,b)]>p)
				rod[pii(a,b)]=p;
		}
		else {
			if (!one[pii(a,b)]||one[pii(a,b)]>p)
				one[pii(a,b)]=p;
		}
	}
	for (auto [i,j]:rod){
		if (!one[i]||one[i]>j)
			one[i]=j;
	}
	vector<pii>tmp;
	for (auto [i,j]:one){
		if (!one[pii(i.y,i.x)])
			tmp.push_back(pii(i.y,i.x));
	}
	for (auto i:tmp)
		one[i]=1e17;
	for (auto [i,j]:one){
		int val=one[i]+one[pii(i.y,i.x)];
		if (!rod[i]||rod[i]>val)
			rod[i]=val;
		if (!rod[pii(i.y,i.x)]||rod[pii(i.y,i.x)]>val)
			rod[pii(i.y,i.x)]=val;
	}
	for (auto i:id)
		solve(i.x);
	cout<<ans<<'\n';
}

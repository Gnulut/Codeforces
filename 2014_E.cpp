#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	const int MAX_SIZE=201000;
	int t,n,m,h;
	vector<pair<int,int>> ed[MAX_SIZE];
	vector<bool> horses(MAX_SIZE);
	long long robin[MAX_SIZE][2], marian[MAX_SIZE][2];
	priority_queue<pair<pair<long long,int>,int>,vector<pair<pair<long long,int>,int>>,greater<pair<pair<long long,int>,int>>> pq;
	cin>>t;
	while(t--){
		cin>>n>>m>>h;
		for(int i=1;i<=n;++i)ed[i].clear();//O(n)
		horses.assign(n+1,false);//O(n)
		for(int i=0,v;i<h;++i){
			cin>>v;
			horses[v]=true;
		}
		for(int i=0,u,v,c;i<m;++i){//O(m)
			cin>>u>>v>>c;
			ed[u].push_back({c,v});
			ed[v].push_back({c,u});
		}
		for(int i=1;i<=n;++i){//O(n)
			robin[i][0]=robin[i][1]=marian[i][0]=marian[i][1]=2e18;
		}
		robin[1][0]=0;
		if(horses[1])robin[1][1]=0;
		marian[n][0]=0;
		if(horses[n])marian[n][1]=0;
		
		pq.push({{0,1},horses[1]});
		while(!pq.empty()){
			pair<long long,int> c_p=pq.top().first;
			bool have_horse = pq.top().second||horses[c_p.second];
			pq.pop();
			if(c_p.first>robin[c_p.second][have_horse])continue;
			for(auto&neighbour:ed[c_p.second]){
				long long ncost = c_p.first+(neighbour.first/(have_horse?2:1));
				if(robin[neighbour.second][have_horse]<=ncost||robin[neighbour.second][1]<=ncost)continue;
				robin[neighbour.second][have_horse]=ncost;
				pq.push({{ncost,neighbour.second},have_horse});
			}
		}
		pq.push({{0,n},horses[n]});
		while(!pq.empty()){
			pair<long long,int> c_p=pq.top().first;
			bool have_horse = pq.top().second||horses[c_p.second];
			pq.pop();
			if(c_p.first>marian[c_p.second][have_horse])continue;
			for(auto&neighbour:ed[c_p.second]){
				long long ncost = c_p.first+neighbour.first/(have_horse?2:1);
				if(marian[neighbour.second][have_horse]<=ncost||marian[neighbour.second][1]<=ncost)continue;
				marian[neighbour.second][have_horse]=ncost;
				pq.push({{ncost,neighbour.second},have_horse});
			}
		}
		long long ans=2e18;
		for(int i=1;i<=n;++i){//O(n)
			//cout<<" i = "<<i<<"   robin["<<i<<"] = "<<robin[i][0]<<","<<robin[i][1]<<"    marian["<<i<<"] = "<<marian[i][0]<<","<<marian[i][1]<<"\n";
			ans = min(ans,max(min(robin[i][0],robin[i][1]),min(marian[i][0],marian[i][1])));
		}
		if(ans<1e18)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<set<int>> ed(n+1);
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			ed[u].insert(v);
			ed[v].insert(u);
		}
		queue<int> q;
		bool destroyed[n+1]={};
		for(int i=1;i<=n;++i){
			if(ed[i].size()==1)q.push(i);
		}
		while(!q.empty()){
			int x = q.front();q.pop();
			if(destroyed[x])continue;
			int destroy_v = *ed[x].begin();
			destroyed[destroy_v]=true;
			for(auto&u:ed[destroy_v]){
				ed[u].erase(destroy_v);
				if(ed[u].size()==1){
					q.push(u);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(!destroyed[i]){
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
}

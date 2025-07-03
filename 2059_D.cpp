#include<bits/stdc++.h>
using namespace std;

int DP[1000][1000];
vector<set<int>> edges[2]={vector<set<int>>(1000),vector<set<int>>(1000)};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,s1,s2;
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2;
		s1--,s2--;
		int m[2];
		for(int rep=0;rep<2;++rep){
			cin>>m[rep];
			vector<set<int>> &this_edges=edges[rep];
			for(int i=0;i<n;++i)this_edges[i].clear();
			for(int i=0,u,v;i<m[rep];++i){
				cin>>u>>v;
				--u,--v;
				this_edges[u].insert(v);
				this_edges[v].insert(u);
			}
		}
		memset(DP,-1,sizeof(DP[0])*n);
		priority_queue<pair<int,pair<int,int>>> pq;
		pq.push({0,{s1,s2}});
		DP[s1][s2]=0;
		while(!pq.empty()){
			int cost=-pq.top().first;
			int v1=pq.top().second.first;
			int v2=pq.top().second.second;
			pq.pop();
			if(cost>DP[v1][v2])continue;
			for(auto&ed1:edges[0][v1]){
				for(auto&ed2:edges[1][v2]){
					int ncost = cost + (abs(ed1-ed2));
					if(DP[ed1][ed2]==-1||ncost<DP[ed1][ed2]){
						DP[ed1][ed2]=ncost;
						pq.push({-ncost,{ed1,ed2}});
					}
				}
			}
		}
		int ans=-1;
		for(int vertex=0;vertex<n;++vertex){
			if(DP[vertex][vertex]==-1)continue;
			for(auto&ed1:edges[0][vertex]){
				if(edges[1][vertex].count(ed1)){
					if(ans==-1||DP[vertex][vertex]<ans){
						ans=DP[vertex][vertex];
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
}

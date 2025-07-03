#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m1,m2;
		cin>>n>>m1>>m2;
		queue<pair<int,int>> q_F;
		for(int i=0,u,v;i<m1;++i){
			cin>>u>>v;
			if(u>v){
				swap(u,v);
			}
			q_F.push({u,v});
		}
		vector<int> loc_of_G(n+1);
		vector<set<int>> group_G(n+1);
		for(int i=1;i<=n;++i){
			loc_of_G[i]=i;
			group_G[i].insert(i);
		}
		for(int i=0,u,v;i<m2;++i){
			cin>>u>>v;
			if(u>v){
				swap(u,v);
			}
			int loc_small = loc_of_G[u], loc_big = loc_of_G[v];
			if(loc_small==loc_big)continue;
			set<int> *small_group = &group_G[loc_small], *big_group = &group_G[loc_big];
			if(small_group->size()>big_group->size()){
				//swap(u,v);
				swap(loc_small,loc_big);
				swap(small_group,big_group);
			}
			for(auto&w:*small_group){
				loc_of_G[w]=loc_big;
				big_group->insert(w);
			}
			small_group->clear();
		}
//		cout<<"G Groups:\n";
//		for(int i=1;i<=n;++i){
//			if(group_G[i].size()){
//				for(auto&x:group_G[i]){
//					cout<<x<<" ";
//				}
//				cout<<"\n";
//			}
//		}
//		for(int relo=0,i=1;i<=n;++i){
//			if(group_G[i].size()==0)continue;
//			swap(group_G[relo],group_G[i]);
//			for(auto&u:group_G[relo]){
//				loc_of_G[u]=relo;
//			}
//			relo++;
//		}
		int ans=0;
		int rep=q_F.size();
		while(rep--){
			pair<int,int> uv=q_F.front();q_F.pop();
			if(loc_of_G[uv.first]==loc_of_G[uv.second]){
				q_F.push(uv);
			}else{
				++ans;
			}
		}
//		cout<<"Removed edges = "<<ans<<"\n";
		vector<int> loc_of_F(n+1);
		vector<set<int>> group_F(n+1);
		for(int i=1;i<=n;++i){
			loc_of_F[i]=i;
			group_F[i].insert(i);
		}
		while(!q_F.empty()){
			int u=q_F.front().first, v=q_F.front().second;q_F.pop();
			int loc_small = loc_of_F[u], loc_big = loc_of_F[v];
			if(loc_small==loc_big)continue;
			set<int> *small_group = &group_F[loc_small], *big_group = &group_F[loc_big];
			if(small_group->size()>big_group->size()){
				//swap(u,v);
				swap(loc_small,loc_big);
				swap(small_group,big_group);
			}
			for(auto&w:*small_group){
				loc_of_F[w]=loc_big;
				big_group->insert(w);
			}
			small_group->clear();
		}
//		cout<<"F group with removed unuseable edges:\n";
//		for(int i=1;i<=n;++i){
//			if(group_F[i].size()){
//				for(auto&x:group_F[i]){
//					cout<<x<<" ";
//				}
//				cout<<"\n";
//			}
//		}
		vector<bool> vis(n+1);
		for(int u=1;u<=n;++u){
			if(vis[u])continue;
			int root_location = loc_of_F[u];
			set<int> &root_group = group_F[root_location];
			for(auto&v:root_group){
				vis[v]=true;
			}
			//get all the people that should be in the same group as u;
//			vector<int> merge_groups;
			for(auto&v:group_G[loc_of_G[u]]){
				if(vis[v])continue;
				++ans;
				for(auto&w:group_F[loc_of_F[v]]){
					vis[w]=true;
				}
//				merge_groups.push_back(loc_of_F[v]);
			}
//			for(auto&group_idx:merge_groups){
//				for(auto&v:group_F[group_idx]){
//					vis[v]=true;
//					loc_of_F[v]=root_location;
//					root_group.insert(v);
//				}
//			}
		}
//		cout<<"ans = ";
		cout<<ans<<"\n";
	}
}

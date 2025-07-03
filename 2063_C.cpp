#include<bits/stdc++.h>
using namespace std;

vector<int> edges[(int)2.1e5];

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			edges[i].clear();
		}
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if(n<=5){
			cout<<n-2<<"\n";
			continue;
		}
		set<pair<int,int>> rank;
		for(int i=1;i<=n;++i){
			rank.insert({edges[i].size(), i});
		}
		int ans=0;
		for(int first_choice=1;first_choice<=n;++first_choice){
			rank.erase({edges[first_choice].size(), first_choice});
			for(auto&edge:edges[first_choice]){
				rank.erase({edges[edge].size(), edge});
				rank.insert({edges[edge].size()-1, edge});
			}
			int new_ans = edges[first_choice].size()+(prev(rank.end())->first)-1;
			//cout<<"first_choice = "<<first_choice<<" new_ans = "<<new_ans<<"\n";
			//cout<<"second choice = "<<(prev(rank.end())->second)<<" rank = "<<(prev(rank.end())->first)<<"\n";
			ans=max(ans,new_ans);
			for(auto&edge:edges[first_choice]){
				rank.erase({edges[edge].size()-1, edge});
				rank.insert({edges[edge].size(), edge});
			}
			rank.insert({edges[first_choice].size(), first_choice});
		}
		cout<<ans<<"\n";
	}
}

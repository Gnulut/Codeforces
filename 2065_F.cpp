#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> edges[(int)5.1e5];
string ans;
vector<bool> vis;
vector<int> a;
void dfs(int node, int par){
	for(auto&ed:edges[node]){
		if(ed==par)continue;
		if(a[node]==a[ed]){
			ans[a[node]]='1';
		}else if(par!=-1&&a[par]==a[ed]){
			ans[a[par]]='1';
		}
		dfs(ed,node);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	
	
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
			x--;
		}
		for(int i=0;i<n;++i){
			edges[i].clear();
		}
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			u--;
			v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		ans=string(n,'0');
		vis.assign(n,false);
//		cout<<"vals = ";
//		for(auto&x:a)cout<<x<<" ";cout<<"\n";
//		for(int i=0;i<n;++i){
//			if(vis[i]||ans[a[i]]=='1')continue;
////			cout<<"working on : "<<i<<"\n";
//			
//			for(auto&ed1:edges[i]){
//				if(a[i]==a[ed1]){
////					cout<<" i =  "<<i<<"  ed1 = "<<ed1<<"\n";
//					vis[i]=vis[ed1]=true;
//					ans[a[i]]='1';
//					break;
//				}
////				if(vis[ed1])continue;
//				for(auto&ed2:edges[ed1]){
//					if(ed2==i)continue;
//					if(a[i]==a[ed2]){
////						cout<<" i =  "<<i<<"  ed2 = "<<ed2<<"\n";
//						vis[i]=vis[ed2]=true;
//						ans[a[i]]='1';
//						break;
//					}else if(a[ed1]==a[ed2]){
////						cout<<" ed1 =  "<<ed1<<"  ed2 = "<<ed2<<"\n";
//						vis[ed1]=vis[ed2]=true;
//						ans[a[ed1]]='1';
//					}
//				}
//			}
////			cout<<"after i: "<<i<<"   "<<ans<<"\n"; 
//		}
		dfs(0,-1);
		cout<<ans<<"\n";
	}
}

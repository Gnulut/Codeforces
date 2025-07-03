#include<bits/stdc++.h>
using namespace std;

void leafs(vector<vector<int>>&edges, string&s,vector<bool>&is_leaf,int node=1,int par=-1){
	if(edges[node].size()==1&&node!=1){
		is_leaf[node]=true;
		return;
	}
	for(auto&edge:edges[node]){
		if(edge!=par){
			leafs(edges,s,is_leaf,edge,node);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int>> edges(n+1);
		string s;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		cin>>s;
		vector<bool> is_leaf(n+1);
		leafs(edges,s,is_leaf);
		int cnt[3]={},cntq=0;
		for(auto&c:s){
			cntq+=c=='?';
		}
		for(int i=1;i<=n;++i){
			if(is_leaf[i]){
				if(s[i-1]=='?'){
					cnt[2]++;
				}else{
					cnt[s[i-1]-'0']++;
				}
			}
		}
		//cout<<"is leaf = ";for(int i=1;i<=n;++i){	cout<<is_leaf[i];}cout<<"\n";
		//for(int i=0;i<3;++i)cout<<cnt[i]<<" ";
		int ans=0;
		if(s[0]=='?'){
			//cout<<"hoy ";
			if(cnt[0]!=cnt[1]){
				ans=max(cnt[0],cnt[1]);
				ans+=cnt[2]/2;
			}else{
				if(cnt[2]%2==0){
					ans=cnt[2]/2;
				}else{
					int cntq_nleaf=cntq-cnt[2]-1;
					ans=(cnt[2]+(cntq_nleaf&1))/2;
				}
				ans+=max(cnt[0],cnt[1]);
			}
		}else{
			//cout<<"hey ";
			if(s[0]=='1'){
				ans=cnt[0]+(cnt[2]+1)/2;
			}else{
				ans=cnt[1]+(cnt[2]+1)/2;
			}
		}
		cout<<ans<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;
const int siz=5.1e5;
pair<int,vector<int>> p_ed[siz];
int d[siz],dcount[siz];
void set_p(int idx,int par){
	p_ed[idx].first=par;
	for(auto&x:p_ed[idx].second){
		if(x!=par){
			set_p(x,idx);
		}
	}
}

int set_d(int idx,int par){
	d[idx]=d[par]+1;
	for(auto&x:p_ed[idx].second){
		if(x!=par){
			set_d(x,idx);
		}
	}
}

int deepest(vector<bool>&vis,int idx,int&con,int&prun){//add into tree
//	cout<<"called "<<idx<<"\n";
	++con;--prun;
	vis[idx]=true;
	if(!vis[p_ed[idx].first]){
		deepest(vis,p_ed[idx].first,con,prun);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			p_ed[i].first=0;
			p_ed[i].second.clear();
		}
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			p_ed[u].second.push_back(v);
			p_ed[v].second.push_back(u);
		}
		set_p(1,0);
		set_d(1,0);
		
//		cout<<"par: ";
//		for(int i=1;i<=n;++i)cout<<p_ed[i].first<<" ";
//		cout<<"\n";
//		cout<<"depth: ";
//		for(int i=1;i<=n;++i)cout<<d[i]<<" ";
//		cout<<"\n";
		vector<bool> vis(n+5);vis[0]=true;//vis true = inside tree
		int ans=n-1;
		int con=0,pruned_cnt=n;
		int dmax=*max_element(d+1,d+n+1);
		vector<set<int>> at_d(dmax+5);//unpruned_at depth
		for(int i=1;i<=n;++i){
			if(d[i]==dmax){
				deepest(vis,i,con,pruned_cnt);//dont prune this
			}
		}
		//vector<vector<int>> pruned(dmax+5);//pruned at depth
		
		for(int i=1;i<=n;++i){
			if(vis[i]){
				//pruned[d[i]].push_back(i);
			}else{
				at_d[d[i]].insert(i);
			}
		}
//		cout<<"at_d check\n";
//		for(auto&x:at_d){
//			for(auto&y:x)cout<<y<<" ";
//			cout<<"\n";
//		}
//		cout<<"\n";
		for(int i=1;i<=dmax;++i){
			dcount[i]=0;
		}
		for(int i=1;i<=n;++i){
			dcount[d[i]]++;
		}
//		cout<<"here\n";
		pruned_cnt=n-con;
		ans=min(ans,pruned_cnt);
//		cout<<" pre pruned = "<<pruned_cnt<<"\n";
		for(int cdepth=dmax-1;cdepth>=2;--cdepth){
//			cout<<"cdepth = "<<cdepth<<"\n";
			//add at d which is pruned previously
			for(auto&x:at_d[cdepth]){
//				cout<<"loop prev "<<x<<"\n";
				if(!vis[x]){
//					cout<<"loop "<<x<<"\n";
					deepest(vis,x,con,pruned_cnt);
				}
			}
//			cout<<"finito";
			//prune all which are too deep
			con-=dcount[cdepth+1];
			pruned_cnt+=dcount[cdepth+1];
//			cout<<"depth = "<<cdepth<<"  pruned "<<pruned_cnt<<"\n";
			ans=min(ans,pruned_cnt);
		}
//		cout<<"ans == ";
		cout<<ans<<"\n";
	}
}

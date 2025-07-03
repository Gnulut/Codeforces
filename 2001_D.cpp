#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a,last;
	vector<bool> used;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a)cin>>x;
		last.assign(n+1,INT_MAX);
		for(int i=0;i<n;++i){
			last[a[i]]=i;
		}
		used.assign(n+1,false);
		priority_queue<int,vector<int>,greater<int>> ls(last.begin(),last.end());
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mx_cand,mn_cand;
		for(int i=0;i<=ls.top();++i){
			mx_cand.push({-a[i],i});
			mn_cand.push({a[i],i});
		}
		vector<int> ans;
		int cutoff=0;
		while(!mx_cand.empty()){
			pair<int,int> x_pos=(ans.size()&1?mn_cand.top():mx_cand.top());
			if(ans.size()&1){
				mn_cand.pop();
			}else{
				x_pos.first*=-1;
				mx_cand.pop();
			}
			ans.push_back(x_pos.first);
			used[x_pos.first]=true;
			cutoff=x_pos.second;
			//cout<<cutoff<<" "<<x_pos.first<<" "<<x_pos.second<<"\n";
			while(ls.top()!=INT_MAX && used[a[ls.top()]]){
				int l=ls.top()+1;ls.pop();
				for(int r=min(ls.top(),n-1);l<=r;++l){
					mx_cand.push({-a[l],l});
					mn_cand.push({a[l],l});
				}
			}
			while(!mx_cand.empty()&&(used[-mx_cand.top().first]||mx_cand.top().second<=cutoff))mx_cand.pop();
			while(!mn_cand.empty()&&(used[mn_cand.top().first]||mn_cand.top().second<=cutoff))mn_cand.pop();
		}
		cout<<ans.size()<<"\n";
		for(auto&x:ans)cout<<x<<" ";
		cout<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

void setans(vector<int>&ans,vector<int>&a,vector<bool>&vis,string&s,int idx,int&ret){
	if(s[idx-1]=='0')++ret;
	vis[idx]=true;
	if(!vis[a[idx]])
		setans(ans,a,vis,s,a[idx],ret);
	ans[idx]=ret;
}

int main(){
	int t,n;
	vector<int> a;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n+1);
		for(int i=1;i<=n;++i)cin>>a[i];
		cin>>s;
		vector<int> ans(n+1);
		vector<bool> vis(n+1);
		for(int i=1;i<=n;++i){
			int c_ret=0;
			if(!vis[i])
				setans(ans,a,vis,s,i,c_ret);
		}
		for(int i=1;i<=n;++i)cout<<ans[i]<<" ";cout<<"\n";
	}
}

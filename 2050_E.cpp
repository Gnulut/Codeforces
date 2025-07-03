#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> DP;
int solve(string&a,string&b,string&c,int ai=0,int bi=0,int ci=0){
	if(DP[ai][bi]!=-1)return DP[ai][bi];
	int ans=999999;
	if(ai<a.length()){
		ans=min(ans,(a[ai]!=c[ci])+solve(a,b,c,ai+1,bi,ci+1));
	}
	if(bi<b.length()){
		ans=min(ans,(b[bi]!=c[ci])+solve(a,b,c,ai,bi+1,ci+1));
	}
	return DP[ai][bi]=ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);//cout.tie(0);
	int t;
	string a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		DP.assign(a.length()+1,vector<int>(b.length()+1,-1));
		DP[a.length()][b.length()]=0;
		cout<<solve(a,b,c)<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;


void solution(vector<vector<char>>&grid,vector<bool>&vis,set<int>&allowed_val, int val){
	if(vis[val])return;
	vis[val]=true;
	vector<char>&crow = grid[val];
	vector<int> left,right;
	for(int i=val+1;i<grid.size();++i){
		if(allowed_val.count(i)==0)continue;
		if(crow[i]=='0'){
			left.push_back(i);
		}else{
			right.push_back(i);
		}
	}
	set<int> left_allowed(left.begin(),left.end());
	for(auto&x:left){
		solution(grid,vis,left_allowed,x);
	}
	cout<<val+1<<" ";
	set<int> right_allowed(right.begin(),right.end());
	for(auto&x:right){
		solution(grid,vis,right_allowed,x);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<char>> g(n,vector<char>(n));
		vector<bool> vis(n);
		set<int> allowed_val;
		for(int i=0;i<n;++i)allowed_val.insert(i);
		for(auto&r:g)for(auto&c:r)cin>>c;
		solution(g,vis,allowed_val,0);
		cout<<"\n";
	}
}

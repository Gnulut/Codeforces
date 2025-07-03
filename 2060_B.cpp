#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int>> v(n,vector<int>(m));
		for(auto&r:v)for(auto&c:r)cin>>c;
		bool can=true;
		vector<int> per(n);
		for(int i=0;i<n;++i){
			sort(v[i].begin(),v[i].end());
			if(v[i].front()>=n){
				can=false;
				break;
			}
			for(int j=1;j<m;++j){
				if(v[i][j-1]+n!=v[i][j]){
					can=false;
					break;
				}
			}
			if(can){
				per[v[i].front()]=i+1;
			}
		}
		if(can){
			for(auto&x:per)cout<<x<<" ";cout<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
}

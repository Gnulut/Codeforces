#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n,m;
	string s;
	vector<ll> graph[1005];
	cin>>t;
	while(t--){
		cin>>n>>m>>s;
		for(int i=0;i<n;++i){
			graph[i].resize(m);
			for(auto&x:graph[i]){
				cin>>x;
			}
		}
		vector<ll> csum(m),rsum(n);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				csum[j]+=graph[i][j];
				rsum[i]+=graph[i][j];
			}
		}
		int y=0,x=0;
		for(auto&c:s){
			if(c=='D'){
				csum[x]+=graph[y][x]=-rsum[y];
				rsum[y]=0;
				y++;
			}else{
				rsum[y]+=graph[y][x]=-csum[x];
				csum[x]=0;
				x++;
			}
		}
		graph[n-1][m-1]=-csum[m-1];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}

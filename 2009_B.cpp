#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n;
	vector<string> g;
	cin>>t;
	while(t--){
		cin>>n;
		g.resize(n);
		for(auto&r:g)cin>>r;
		for(int i=n-1;i>=0;--i){
			for(int j=0;j<4;++j){
				if(g[i][j]=='#'){
					cout<<j+1<<" ";
				}
			}
		}
		cout<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		vector<int> not_present(m);
		for(auto&x:not_present){
			cin>>x;
		}
		vector<int> know(k);
		for(auto&x:know){
			cin>>x;
		}
		if(k==n){
			cout<<string(m,'1')<<'\n';
			continue;
		}else if(k<n-1){
			cout<<string(m,'0')<<'\n';
			continue;
		}
		string ans(m,'0');
		int unknown=1;
		for(auto&x:know){
			if(x!=unknown)break;
			++unknown;
		}
		for(int i=0;i<m;++i){
			if(not_present[i]==unknown){
				ans[i]='1';
				break;
			}
		}
		cout<<ans<<"\n";
	}
}

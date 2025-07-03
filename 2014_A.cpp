#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,k;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n>>k;
		a.resize(n);
		for(auto&ai:a)cin>>ai;
		int ans=0,gold=0;
		for(auto&ai:a){
			if(ai>=k){
				gold+=ai;
			}else if(ai==0&&gold){
				gold--;
				++ans;
			}
		}
		cout<<ans<<"\n";
	}
}

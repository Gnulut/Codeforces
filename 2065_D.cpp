#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m;
	vector<pair<pair<long long, long long>,vector<int>>> a;
	cin>>t;
	while(t--){
		cin>>n>>m;
		a.resize(n);
		for(auto&ai:a){
			ai.first.first=0;
			ai.first.second=0;
			ai.second.resize(m);
			long long rep=m;
			for(auto&x:ai.second){
				cin>>x;
				ai.first.first+=x;
				ai.first.second+=x*rep;
				rep--;
			}
		}
		vector<pair<pair<long long,long long>,vector<int>>*> p(n);
		for(int i=0;i<n;++i){
			p[i]=&a[i];
		}
		sort(p.begin(),p.end(),[](pair<pair<long long,long long>,vector<int>>* l, pair<pair<long long,long long>,vector<int>>* r){
			if(l->first.first!=r->first.first) return l->first.first>r->first.first;
			return l->first.second>r->first.second;
		});
		long long ans=0,rep=n*m;
		for(int i=0;i<n;++i){
			//cout<<p[i]->first.first<<"  "<<p[i]->first.second<<":  ";
			for(int j=0;j<m;++j){
				ans+=rep*(p[i]->second[j]);
				//cout<<ans<<"  ";
				rep--;
			}
			//cout<<"\n";
		}
		cout<<ans<<"\n";
	}
}

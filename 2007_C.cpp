#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,a,b;
	vector<int> c;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		c.resize(n);
		for(auto&ci:c)cin>>ci;
		int gc=__gcd(a,b);
		set<int> s;
		for(auto&ci:c){
			s.insert(ci%gc);
		}
		int rep=s.size();
		int ans=-*s.begin()+*prev(s.end());
		while(rep--){
			auto f=s.begin();
			int val=*f;
			s.erase(f);
			s.insert(val+gc);
			ans=min(ans,*prev(s.end())-*s.begin());
		}
		cout<<ans<<"\n";
	}
}

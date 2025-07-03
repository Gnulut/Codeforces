#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&ai:a){
			cin>>ai;
		}
		int ans=0;
		set<long long> s;s.insert(0);
		long long cval=0;
		for(auto&ai:a){
			cval+=ai;
			if(s.find(cval)!=s.end()){
				++ans;
				s.clear();
				cval=0;
			}
			s.insert(cval);
		}
		cout<<ans<<"\n";
	}
}

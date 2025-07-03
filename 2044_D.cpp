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
		set<int> s;
		for(int i=1;i<=n;++i){
			s.insert(i);
		}
		for(auto&ai:a){
			auto it = s.find(ai);
			if(it!=s.end()){
				cout<<*it<<" ";
				s.erase(it);
			}else{
				cout<<*s.begin()<<" ";
				s.erase(s.begin());
			}
		}
		cout<<"\n";
	}
}

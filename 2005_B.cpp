#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,m,q;
	cin>>t;
	vector<int> a;
	while(t--){
		cin>>n>>m>>q;
		a.resize(m);
		for(auto&ai:a)cin>>ai;
		sort(a.begin(),a.end());
		int dvid;
		while(q--){
			cin>>dvid;
			int l=-1,r=-1;
			vector<int>::iterator it = lower_bound(a.begin(),a.end(),dvid);
			if(it!=a.begin()){
				l=*(it-1);
			}
			if(it!=a.end()){
				r=*it;
			}
			if(l!=-1&&r!=-1){
				cout<<(r-l)/2<<"\n";
			}else if(l!=-1){
				cout<<(n-l)<<"\n";
			}else{
				cout<<(r-1)<<"\n";
			}
		}
	}
}

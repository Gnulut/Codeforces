#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	vector<pair<int,int>> circ;
	long long xs,ys,xt,yt;
	cin>>t;
	while(t--){
		cin>>n;
		circ.resize(n);
		for(auto&ii:circ){
			cin>>ii.first>>ii.second;
		}
		cin>>xs>>ys>>xt>>yt;
		long long timesq = (xs-xt)*(xs-xt)+(ys-yt)*(ys-yt);
		bool can=true;
		for(auto&ii:circ){
			if((ii.first-xt)*(ii.first-xt)+(ii.second-yt)*(ii.second-yt)<=timesq){
				can=false;
				break;
			}
		}
		cout<<(can?"YES\n":"NO\n");
	}
}

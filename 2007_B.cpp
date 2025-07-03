#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m,l,r;
	char c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int mx=0,tmp;
		for(int i=0;i<n;++i){
			cin>>tmp;
			mx=max(mx,tmp);
		}
		for(int i=0;i<m;++i){
			cin>>c>>l>>r;
			if(l<=mx&&mx<=r){
				if(c=='+')++mx;
				else --mx;
			}
			cout<<mx<<" ";
		}
		cout<<"\n";
	}
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<1;
		for(int i=1;i<=n/2;++i){
			cout<<" "<<i;
		}
		for(int i=1;i<=(n-1)/2;++i){
			cout<<" "<<i;
		}
		cout<<"\n";
	}
}

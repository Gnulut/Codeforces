#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,x,y;
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		cout<<max((n+x-1)/x,(n+y-1)/y)<<"\n";
	}
}

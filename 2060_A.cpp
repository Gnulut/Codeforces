#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	int a[5];
	cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[3]>>a[4];
		int ans=0;
		map<int,int> m;
		ans=max(ans,++m[a[0]+a[1]]);
		ans=max(ans,++m[a[3]-a[1]]);
		ans=max(ans,++m[a[4]-a[3]]);
		cout<<ans<<"\n";
	}
}

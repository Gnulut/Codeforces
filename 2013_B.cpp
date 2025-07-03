#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a)cin>>x;
		long long ans=a.back()-a[n-2];
		for(int i=n-3;i>=0;--i){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
}

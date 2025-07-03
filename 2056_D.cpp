#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n);
		for(auto&x:a)cin>>x;
		long long ans = n*(n+1ll)/2;
		for(int i=1;i<=10;++i){
			vector<int> b(n+1);
			for(int j=0;j<n;++j){
				b[j+1]=b[j]+(a[j]<=i?-1:1);
			}
			for(auto&x:b)cout<<" "<<x;
			cout<<"\n";
			sort(b.begin(),b.end());
			int cnt=0,val=-1000000000;
			for(auto&x:b){
				if(x!=val){
					val=x;
					cnt=1;
				}else{
					ans-=cnt++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}

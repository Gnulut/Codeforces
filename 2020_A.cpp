#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	long long t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long long ans=0;
		if(k==1){
			cout<<n<<"\n";
			continue;
		}
		while(n){
			ans+=n%k;
			n/=k;
		}
		cout<<ans<<"\n";
	}
}

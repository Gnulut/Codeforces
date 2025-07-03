#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		long long n,ans=1,mult=1;
		cin>>n;
		while(n>3){
			ans+=mult;
			mult*=2;
			n/=4;
		}
		cout<<ans<<"\n";
	}
}

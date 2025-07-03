#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int min_balance = max(n,m)-min(n,m);
		int max_balance = max(n,m);
		if(min_balance>k||max_balance<k){
			cout<<"-1\n";
			continue;
		}
		string ans;
		if(n>m){
			ans+=string(k,'0');
			n-=k;
			while(m&&n){
				ans+='1';
				ans+='0';
				m--;
				n--;
			}
		}else{
			ans+=string(k,'1');
			m-=k;
			while(n&&m){
				ans+='0';
				ans+='1';
				m--;
				n--;
			}
		}
		ans+=string(n,'0')+string(m,'1');
		cout<<ans<<"\n";
	}
}

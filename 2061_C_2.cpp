#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	const long long mod = 998244353;
	int t,n;
	vector<int> a,status;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		status.assign(n,0);
		for(auto&x:a){
			cin>>x;
		}
		long long ans=1,mult=1,current_liar=0;
		for(int i=0;i<n;++i){
			
			if(a[i]!=current_liar){
				if(i&&status[i-1]==-1){
					mult=1;
					ans=0;
					break;
				}
				current_liar++;
				status[i]=-1;
				mult=1;
//				cout<<" i = "<<i<<"   mult = "<<mult<<"   liars = "<<current_liar<<"   cans = "<<ans<<"\n";
				continue;
			}
			// below here correct amount of liars
			if((i==0||status[i-1]!=-1)&&(i+1==n||a[i+1]==current_liar+1)){
				mult++;
				current_liar++;
				i++;
//				cout<<" i = "<<i<<"   mult = "<<mult<<"   liars = "<<current_liar<<"   cans = "<<ans<<"\n";
				continue;
			}
			if(mult>1){
				ans=ans*mult%mod;
				mult=1;
			}
//			cout<<" i = "<<i<<"   mult = "<<mult<<"   liars = "<<current_liar<<"   cans = "<<ans<<"\n";
		}
		ans=ans*mult%mod;
		cout<<ans<<"\n";
	}
}

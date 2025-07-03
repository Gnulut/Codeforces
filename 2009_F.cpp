#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	long long t,n,q;
	vector<long long> a;
	cin>>t;
	while(t--){
		cin>>n>>q;
		a.resize(n+1);
		for(int i=1;i<=n;++i){
			cin>>a[i];
			a[i]+=a[i-1];
		}
		long long l,r;
		for(int qc=0;qc<q;++qc){
			cin>>l>>r;
			long long ans=0;
			long long cyc_num_l=(l-1)/n+1;
			long long m = min(r,cyc_num_l*n);
			long long st = (l+cyc_num_l-2)%n+1;
			long long ed = (m+cyc_num_l-2)%n+1;
			if(st<=ed){
				ans+=a[ed]-a[st-1];
			}else{
				ans+=a[n]-a[st-1]+a[ed];
			}
			long long cyc_num_r=(r-1)/n+1;
			if(cyc_num_l<cyc_num_r){
				m=max(l,(cyc_num_r-1)*n+1);
				st = (m+cyc_num_r-2)%n+1;
				ed = (r+cyc_num_r-2)%n+1;
				if(st<=ed){
					ans+=a[ed]-a[st-1];
				}else{
					ans+=a[n]-a[st-1]+a[ed];
				}
				ans+=(cyc_num_r-cyc_num_l-1)*a[n];
			}
			cout<<ans<<"\n";
		}
	}
}

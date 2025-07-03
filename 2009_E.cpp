#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	long long t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long long mn=k,mx=k+n-1;
		long long l=mn,r=mx;
		long long ans = 9ll*1000ll*1000ll*1000ll*1000ll*1000ll*1000ll;
		while(l<=r){
			long long m = (l+r)/2;
			long long suml=(mn+m)*(m-mn+1)/2,sumr=(mx+m+1)*(mx-m)/2;
			//cout<<"m = "<<m<<"\tsuml = "<<suml<<"\tsumr = "<<sumr<<"\n";
			ans=min(ans,abs(suml-sumr));
			if(suml==sumr)break;
			if(sumr<suml)r=m-1;
			else l=m+1;
		}
		cout<<ans<<"\n";
	}
}

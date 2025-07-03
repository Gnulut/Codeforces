#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,l,r;
	vector<int> a;
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		l--;
		r--;
		a.resize(n);
		for(auto&x:a){
			cin>>x;
		}
		long long ans=0;
		for(int i=l;i<=r;++i){
			ans+=a[i];
		}
		sort(a.begin(),a.begin()+l);
		sort(a.begin()+l,a.begin()+r+1);
		sort(a.begin()+r+1,a.end());
		long long max_removal=0,removal=0;
		for(int i=0,j=r;i<l&&j>=l;++i,--j){
			removal+=a[j]-a[i];
			max_removal=max(max_removal,removal);
		}
		removal=0;
		for(int i=r+1,j=r;i<n&&j>=l;++i,--j){
			removal+=a[j]-a[i];
			max_removal=max(max_removal,removal);
		}
		ans=ans-max_removal;
		cout<<ans<<"\n";
	}
}

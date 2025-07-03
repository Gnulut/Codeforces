#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long t,n,x,y;
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		long long total = 0;
		vector<long long> nums(n);
		for(auto&x:nums){
			cin>>x;
			total+=x;
		}
		x-=total;
		y-=total;
		x*=-1;
		y*=-1;
		swap(x,y);
		sort(nums.begin(),nums.end());
		long long ans=0;
		for(auto it=nums.begin();it!=nums.end();++it){
			long long lval=x-*it,rval=y-*it;
			auto itl=lower_bound(nums.begin(),it,lval);
			if(itl==it)continue;
			auto itr=upper_bound(nums.begin(),it,rval);
			ans+=itr-itl;
		}
		cout<<ans<<"\n";
	}
}

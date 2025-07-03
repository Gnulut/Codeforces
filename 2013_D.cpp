#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	vector<long long> a;a.reserve(201*1000);
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n);
		for(auto&x:a)cin>>x;
		long long global_mn=*min_element(a.begin(),a.end());
		long long global_mx=*max_element(a.begin(),a.end());
		long long l=global_mn,r=global_mx;
		while(l<=r){
			long long m = (l+r)/2;//represent cutoff
			long long new_mn=1234567891234567890ll;
			long long surplus=0;
			for(auto&x:a){
				if(x>=m){
					surplus+=x-m;
					new_mn=min(new_mn,m);
				}else{
					long long canuse=min(m-x,surplus);
					surplus-=canuse;
					new_mn=min(new_mn,x+canuse);
				}
			}
			if(surplus){
				l=m+1;
				continue;
			}
			r=m-1;
		}
		//cout<<"best cutoff = "<<l<<"\n";
		long long mn=global_mx,sum=0;
		for(int i=0;i<n;++i){
			sum+=a[i];
			if(a[i]<mn){
				mn=min(mn,sum/(i+1));
			}
			//cout<<"i = "<<i<<"   mn = "<<mn<<"\n";
		}
		cout<<l-mn<<"\n";
	}
}
